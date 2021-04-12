@echo off
rem +-------------------------------------------------------------+
rem |    Author : M.W.Richardson                                  |
rem |    Date   : 22/02/2019                                      |
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

if errorlevel 1 pause
