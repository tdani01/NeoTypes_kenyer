#!/bin/sh

gcc -c Source/*.c -m64
ar rcs 'Linux (x86_64)/libNeoTypes.a' *.o
rm *.o

x86_64-w64-mingw32-gcc -c Source/*.c -m64
ar rcs 'Windows (x86_64)/libNeoTypes.a' *.o
rm *.o
