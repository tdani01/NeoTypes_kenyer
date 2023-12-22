@echo off

gcc -o bin.exe *.c -LNeoTypes -lNeoTypesMinGW
if %errorlevel%==0 (
    start ./bin
)
