@echo off
setlocal enableextensions enabledelayedexpansion

set Report=DeviationReport.txt
set NTP=%PROGRAMFILES(X86)%\Notepad++
set TempFile=temp.txt
if exist %Report% del /F %Report%

rem iterate over all c and c++ files
rem ================================
for /R %%f in (*.c,*.cpp,*.h) do (
  set "fname=%%~nxf"
  rem ignore any instrumented file
  if "!fname!"=="!fname:inszt=!" (
	  echo file "%%f" >> %Report%
    FINDSTR /n "LDRA_INSPECTED" %%f > %TempFile%
    for /f "tokens=*" %%i in (!TempFile!) do (
		  echo %%i >> %Report%
    )
    echo. >> %Report%
  )
)

if exist %TempFile% del /F %TempFile%

if exist %Report% goto P1
pause
exit

:P1
if exist "%NTP%\notepad++.exe" goto P2
%TBED%\TBbrowse %Report%
exit

:P2
"%NTP%\notepad++" %Report%
exit
