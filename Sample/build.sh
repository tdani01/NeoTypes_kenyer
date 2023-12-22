#!/bin/sh

gcc -o bin *.c -m64 -LNeoTypes -lNeoTypes && ./bin
