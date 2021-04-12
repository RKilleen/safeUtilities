@echo off
set PRJ_NAME=MPLABX_XC8_Safe_Utilities.X
set TBED=C:\LDRA_Toolsuite
set PRJ_DIR=%~dp0..
set PRJ_TCF="%PRJ_DIR%\..\%PRJ_NAME%.tcf"

cd /d %PRJ_DIR%
call Clean.bat

rem Instrument and build
rem ====================
@echo on
start "ldra" /wait %TBED%\contestbed %PRJ_TCF% /212q
