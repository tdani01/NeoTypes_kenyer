@echo off

gcc -o bin.exe *.c NeoTypes/*.o -lm
if %errorlevel%==0 (
    start ./bin
)
