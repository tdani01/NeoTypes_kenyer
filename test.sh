#!/bin/sh

gcc -o test.out $(find . -name '*.c') -m64 -lm && ./test.out
