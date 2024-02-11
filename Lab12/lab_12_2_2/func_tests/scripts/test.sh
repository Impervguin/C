#!/bin/bash

SUCCESS="\033[92m"
ERROR="\033[91m"
RESET="\033[0m"
KEYS=""
make clean > /dev/null

make unit_tests.exe > /dev/null
./unit_tests.exe
rc=$?

if [[ $rc -eq 0 ]]; then
  echo -e Unit testing: "$SUCCESS"passed"$RESET"
else
  echo -e Unit testing: "$ERROR"failed"$RESET"
fi

out=$(mktemp)

make unit_tests.exe > /dev/null
valgrind --leak-check=yes -q --log-file="$out" ./unit_tests.exe > /dev/null
if [[ -s "$out" ]]; then
  echo -e Unit test memory: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Unit test memory: "$SUCCESS"passed"$RESET"
fi
