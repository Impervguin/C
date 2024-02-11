#!/bin/bash

clang -c -std=c99 -fsanitize=address -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -fno-omit-frame-pointer -O0 -g -o main.o main.c
clang -fsanitize=address -o app.exe  main.o
