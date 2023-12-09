@echo off

gcc -o bin.exe *.c NeoTypes/*.c -lm
if %errorlevel%==0 (
    start ./bin
)
