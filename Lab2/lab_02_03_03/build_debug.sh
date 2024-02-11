#!/bin/bash

gcc -std=c99 -c -g -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc -o app.exe main.o
