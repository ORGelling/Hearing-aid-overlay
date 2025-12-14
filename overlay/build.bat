@echo off
REM Build script for Visual Studio compiler

REM Find and setup Visual Studio environment
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64.bat"

REM Compile
cl.exe /EHsc /W4 /O2 /I. ^
  main.cc handleexception.cc setoptions.cc ^
  arrowoverlay\arrowoverlay1.cc ^
  arrowoverlay\destructor.cc ^
  arrowoverlay\drawarrow.cc ^
  arrowoverlay\initialisewindow.cc ^
  arrowoverlay\mainloop.cc ^
  arrowoverlay\renderframe.cc ^
  arrowoverlay\run.cc ^
  overlayconfig\overlayconfig2.cc ^
  /link SDL2.lib SDL2main.lib /SUBSYSTEM:CONSOLE ^
  /OUT:hearing-aid-overlay.exe

echo.
echo Build complete! Run: hearing-aid-overlay.exe
