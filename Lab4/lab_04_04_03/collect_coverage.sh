#!/bin/bash

./clean.sh

bash build_coverage.sh
bash func_tests/scripts/func_tests.sh
gcov main.c

