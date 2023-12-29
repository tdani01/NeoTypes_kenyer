#!/bin/sh

gcc -o test.out test.c Source/*.c -m64 -lm && ./test.out
