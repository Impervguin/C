#!/bin/bash

gcc -c -std=c99 --coverage -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -o main.o main.c -lm
gcc --coverage -o app.exe main.o -lm