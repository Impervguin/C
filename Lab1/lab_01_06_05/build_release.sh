#!/bin/bash

gcc -c -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc -o app.exe main.o -lm
