@echo off
setlocal enabledelayedexpansion
rem +-------------------------------------------------------------+
rem |    Author : M.W.Richardson                                  |
rem |    Date   : 22/02/2019                                      |
rem |                                                             |
rem | Batch file to automate the import of documents into         |
rem | TBmanager and then to run all tests and generate reports.   |
rem |                                                             |
rem |    Copyright (C) 2019 Liverpool Data Research Associates    |
rem +-------------------------------------------------------------+

set TBED=C:\LDRA_Toolsuite
set TLP=C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\
if exist %TBED%\Utils\Python\Lib\xmllib.py (
  set PYTHON_PATH=%TBED%\Utils\Python
) else (
  set PYTHON_PATH=C:\Python27
)
set PRJ=MPLABX_XC8_Safe_Utilities.X
set COMPILER=Microchip MPLAB X XC8
rem set TBRUNINI=%TLP%xc8_tbrunini_18F26J50.dat
rem set TBRUNINI=%TLP%xc8_tbrunini_16F18875.dat
rem set TBRUNINI=%TLP%xc8_tbrunini_16lF18856.dat
set TBRUNINI=%TLP%xc8_tbrunini.dat
rem set TESTBEDINI=%TLP%xc8_testbedini_18F26J50.dat
rem set TESTBEDINI=%TLP%xc8_testbedini_16F18875.dat
rem set TESTBEDINI=%TLP%xc8_testbedini_16lF18856.dat
set TESTBEDINI=%TLP%xc8_testbedini.dat


set PATH=%PYTHON_PATH%;%TBED%;%PATH%
set ROOT=%~dp0
set TCF=%ROOT%%PRJ%.tcf
set TBP=%ROOT%%PRJ%.tbp
set TMR=%ROOT%report_storage\Traceability_Matrix_Report
set CONFIG_DIR=%ROOT%Configuration
set FIRST="Jane"
set LAST="Wilson"

set TBM=start "ldra" /wait /min TBmanager.exe %TBP% /first=%FIRST% /last=%LAST%
set TBINI=start "ldra" /wait /min TBini.exe

set BASE=%cd%\
cd /d %ROOT%


rem Set the compiler
rem ================
%TBINI% COMPILER_SELECTED="%COMPILER%"
%TBINI% /Section="C/C++ %COMPILER% LDRA Testbed" CSTANDARDS_MODEL=MISRA-C:2012/AMD1
%TBINI% /Section="C/C++ %COMPILER% LDRA Testbed" CEXTERNAL_STANDARD=MISRA-C:2012/AMD1
%TBINI% /Section="C/C++ %COMPILER% LDRA Testbed" METFILE=%CONFIG_DIR%\metpen.dat
%TBINI% /Section="C/C++ %COMPILER% LDRA Testbed" BUILD_OPTIONS_FILE=%TESTBEDINI%
%TBINI% /Section="C/C++ %COMPILER% LDRA Testbed" TBRUN_BUILD_OPTIONS_FILE=%TBRUNINI%


rem Delete the previous results
rem ===========================
@echo Deleting previous results
start "ldra" /wait /min contestbed.exe /delete_set=%PRJ%
call Clean > nul


rem restore project to initial state
rem ================================
@echo Restoring project to initial state
if exist .lock* del /F .lock*
if exist *.xml del /F *.xml
if exist *.htm del /F *.htm
if exist *.exh del /F *.exh
if exist *.txt del /F *.txt
if exist *.cfg del /F *.cfg
if exist %PRJ%.tbp del /F %PRJ%.tbp
if exist *.tbmspec del /F *.tbmspec
if exist *.log del /F *.log
if exist report_storage rmdir /s /q report_storage 
if exist baselines rmdir /s /q baselines 
if exist tbreq rmdir /s /q tbreq 

xcopy /S /Q /i TBmanager_Template . > nul


rem Open project, add source code from tcf and perform analysis
rem ===========================================================
@echo Add source code and run analysis
%TBM% /add_source_from_tcf="%TCF%" /analyse_source /close


rem Re-read all documents
rem =====================
@echo Import word documents
echo %ROOT%Requirements\Safe_Utilities_SLR.docx> Word_Docs.txt
echo %ROOT%Requirements\Safe_Utilities_HLR.docx>> Word_Docs.txt
%TBM% /import_from_word_list=Word_Docs.txt /close

@echo Import excel documents
echo %ROOT%Requirements\Safe_Utilities_LLR.xlsx> Excel_Docs.txt
echo %ROOT%HLR_Tests\Safe_Utilities_HLT.xlsx>> Excel_Docs.txt
echo %ROOT%LLR_Tests\Safe_Utilities_LLT.xlsx>> Excel_Docs.txt
%TBM% /import_from_excel_list=Excel_Docs.txt /close


rem Export the source code description and project
rem ==============================================
@echo Export source code description
%TBM% /export_source_desc=Source_Description.xml /close
@echo Export %PRJ%.tbmspec
%TBM% /export_tbmspec=%PRJ%.tbmspec /close


if not exist "%PYTHON_PATH%\python.exe" (
  @echo Unable to set external tasks or map functions, need to set Python path to Python27 or above, since the python in the LDRA tool suite does not support xml
) else (
  @echo Set External Tasks Program from LLT "program" attribute
  python.exe %ROOT%Set_External_Tasks.py %PRJ%.tbmspec ExternalTasks.tbmspec
  
  @echo Generate Low Level Requirement to Source Code Mapping from LLR "reference" attribute
  python.exe %ROOT%Generate_Mapping.py %PRJ%.tbmspec Source_Description.xml Mapping.tbmspec

  rem Import External Tasks and Source Code Mapping
  rem =============================================
  @echo Import External Tasks 
  %TBM% /import_tbmspec=ExternalTasks.tbmspec /close

  @echo Import Source Code Mapping 
  %TBM% /import_tbmspec=Mapping.tbmspec /close
)


rem Instrument and build the code
rem =============================
@echo Instrument and build
start "ldra" /wait /min contestbed %TCF% /212q


rem Perform Code Review & Quality Review
rem ====================================
@echo Perform code review and quality review
%TBM% /verify_code_review_tcis /verify_quality_review_tcis /close


rem Perform External Tasks
rem ======================
@echo Perform external tasks
%TBM% /verify_external_task_tcis /close


rem Perform the Dynamic Analysis
rem ============================
start "ldra" /wait contestbed %TCF% /32panq /dataset=DynamicAnalysis


rem Generate Dynamic Data Flow Coverage Report
rem ==========================================
@echo Generate dynamic data flow coverage report
start "ldra" /wait /min TBini SCAN_ON_DEMAND=FALSE
start "ldra" /wait /min contestbed %TCF% /run_required_dyndflow /generate_dyndflow_report /q


rem Perform Unit Tests
rem ==================
@echo Perform unit tests
%TBM% /verify_unit_test_tcis /close


rem Perform Code Coverage Review
rem ============================
@echo Perform code coverage review
%TBM% /verify_code_coverage_tcis /close


rem All the traceability reports get the same name, so rename them each time
rem ========================================================================
@echo Generate reports
%TBM% /proj_coverage_summary_report /proj_coverage_report /traceability_report /source_mapping_report /defect_report /unit_test_regression_report /close

%TBM% /traceability_matrix_req_report="SLR,HLR" /close
for %%i in (%TMR%\*Traceability_Matrix_Report.html) do rename %%i SLR_HLR.html

%TBM% /traceability_matrix_req_report="HLR,LLR" /close
for %%i in (%TMR%\*Traceability_Matrix_Report.html) do rename %%i HLR_LLR.html

%TBM% /traceability_matrix_tci_report="HLR,HLT" /close
for %%i in (%TMR%\*Traceability_Matrix_Report.html) do rename %%i HLR_HLT.html

%TBM% /traceability_matrix_tci_report="LLR,LLT" /close
for %%i in (%TMR%\*Traceability_Matrix_Report.html) do rename %%i LLR_LLT.html

rem Remove unwanted reports
rem =======================
@echo Remove unwanted reports
for %%i in (%TMR%\*Traceability_Matrix_Report.html.txt) do del /F %%i


rem Generate a Baseline
rem ===================
@echo Creating a "Creation" baseline
%TBM% /new_project_baseline="Creation" /close


set REPORT="%ROOT%report_storage\Traceability Summary Report.html"

if "%ROOT%"=="%BASE%" (
  rem Run without Jenkins so just open the summary report
  rem ===================================================
  if exist !REPORT! (
    TBbrowse !REPORT!
  )
) else (
  rem Run with Jenkins, so copy reports into the Jenkins workspace
  rem ============================================================
  set REPORT_DIR="!WORKSPACE!"\Report
  if exist !REPORT_DIR! rmdir /s /q !REPORT_DIR!
  if not exist !REPORT_DIR% mkdir !REPORT_DIR!
  xcopy /S /Q /i !ROOT!report_storage !REPORT_DIR!
)

rem Finally set the error to 0 if the reports exist
rem ===============================================
if exist %REPORT% (
  exit /B 0
) else (
  exit /B 1
)
