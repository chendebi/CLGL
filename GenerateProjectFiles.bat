@echo off

call "%~dp0Vendors\Build\Windows\premake5.exe" --file=CLGL.cproject vs2017 %*

if %ERRORLEVEL% NEQ 0 goto Error_BuildProject

exit /B %ERRORLEVEL%

:Error_BuildProject
echo Build Failed!
pause
exit /B 1