@echo off

gcc -o bin.exe *.c -LNeoTypes -lNeoTypes
if %errorlevel%==0 (
    start ./bin
)
