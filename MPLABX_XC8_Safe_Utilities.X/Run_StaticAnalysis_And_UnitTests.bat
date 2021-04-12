@echo off
setlocal
rem +-------------------------------------------------------------+
rem |    Author : M.W.Richardson                                  |
rem |    Date   : 23/09/2019                                      |
rem |                                                             |
rem |    Copyright (C) 2019 Liverpool Data Research Associates    |
rem +-------------------------------------------------------------+

set TBED=C:\LDRA_Toolsuite
set TLP=C:\LDRA_Toolsuite\Compiler_spec\Microchip\xc8\
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
set PATH=%TBED%;%PATH%
set ROOT=%~dp0
set CONFIG_DIR=%ROOT%Configuration

rem Configure relative paths 
rem ========================
set SRC_FILES=%ROOT%%PRJ%.tcf
set WORK=C:\LDRA_Workarea\%PRJ%_tbwrkfls

set TBI=start "ldra" /wait /min TBini.exe
set TBS=%TBI% /Section="C/C++ %COMPILER% LDRA Testbed"
if exist "%TBED%\contestbed.exe" set TOOL=start "ldra" /wait /min contestbed
if exist "%TBED%\conunit.exe" set TOOL=start "ldra" /wait /min conunit


rem Set the compiler
rem ================
%TBI% COMPILER_SELECTED="%COMPILER%"
%TBS% METFILE=%CONFIG_DIR%\metpen.dat
%TBS% BUILD_OPTIONS_FILE=%TESTBEDINI%
%TBS% TBRUN_BUILD_OPTIONS_FILE=%TBRUNINI%


rem Delete the existing set and work directory
rem ==========================================
@echo Deleting Existing Results
%TOOL% /delete_set=%PRJ%
if exist %WORK% rmdir /s /q %WORK%


rem Run the Main Static, Complexity Analysis, Data Flow, Information Flow & Instrumentation
rem =======================================================================================
@echo Running Analysis
%TOOL% %SRC_FILES% /112a34021q

rem Run each sequence in the TCF directory
rem ======================================
set TCF_ROOT=%ROOT%LowLevelTests
set CSP_FILE=%TCF_ROOT%\Tests.csp
if exist %CSP_FILE% del /F %CSP_FILE%

for %%i in (%TCF_ROOT%\*.tcf) do (
  @echo /tcf=%%i >> %CSP_FILE%
  @echo /regress >> %CSP_FILE%
  @echo /close >> %CSP_FILE%
)

@echo Regressing %CSP_FILE%
%TOOL% %SRC_FILES% /1q /tbruncsp=%CSP_FILE%

rem Generate a Test Manager Report
rem ==============================
%TOOL% %SRC_FILES% /generate_overview_rep

rem Open the Test Manager Report
rem ============================
if exist "%WORK%\%PRJ%.ovs.htm" TBbrowse "%WORK%\%PRJ%.ovs.htm"
