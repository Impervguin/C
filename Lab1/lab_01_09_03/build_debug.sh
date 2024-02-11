#!/bin/bash

gcc  -g -std=c99 -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc -o app.exe main.o
