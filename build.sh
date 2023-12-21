#!/bin/sh

gcc -c *.c && ar rcs libNeoTypes.a *.o && rm *.o