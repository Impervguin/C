#!/bin/bash

clang -std=c99 -fsanitize=undefined -c -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fno-omit-frame-pointer -g -O0 -o main.o main.c
clang -fsanitize=undefined -o app.exe  main.o
