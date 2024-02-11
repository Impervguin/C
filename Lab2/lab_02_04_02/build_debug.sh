#!/bin/bash

gcc -std=c99 -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o -g main.o main.c -lm
gcc -o app.exe main.o
