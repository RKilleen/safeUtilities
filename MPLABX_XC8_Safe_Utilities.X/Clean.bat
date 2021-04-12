set mplabx=C:\Program Files (x86)\Microchip\MPLABX\v5.35\
set path=%mplabx%mplab_ide\bin;%mplabx%mplab_platform\bin;%mplabx%gnuBins\GnuWin32\bin;%PATH%;
set proj=%cd%

call prjMakefilesGenerator.bat %proj%
make clean

if errorlevel = 1 pause
