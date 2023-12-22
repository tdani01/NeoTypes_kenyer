#!/bin/sh

gcc -c *.c -m64 && ar rcs libNeoTypes.a *.o && rm *.o