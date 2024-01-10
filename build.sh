#!/bin/sh

cp Source/*.h 'Linux (x86_64)'
gcc -c Source/*.c -m64
ar rcs 'Linux (x86_64)/libNeoTypes.a' *.o
rm *.o

cp Source/*.h 'Windows (x86_64)'
x86_64-w64-mingw32-gcc -c Source/*.c -m64
ar rcs 'Windows (x86_64)/libNeoTypes.a' *.o
rm *.o
