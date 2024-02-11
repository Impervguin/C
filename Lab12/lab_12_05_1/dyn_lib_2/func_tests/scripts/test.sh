#!/bin/bash

SUCCESS="\033[92m"
ERROR="\033[91m"
RESET="\033[0m"
KEYS=""
make clean > /dev/null
make release > /dev/null
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh -v --mem-check $KEYS # Если добавить в кавычки, то вся строка keys будет параметром


make clean > /dev/null
make debug_asan > /dev/null
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Address sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Address sanitizer: "$SUCCESS"passed"$RESET"
fi

make clean > /dev/null
make debug_msan > /dev/null

# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Memory sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Memory sanitizer: "$SUCCESS"passed"$RESET"
fi

make clean > /dev/null
make debug_ubsan > /dev/null
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Undefined behavior sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Undefined behavior sanitizer: "$SUCCESS"passed"$RESET"
fi

make clean > /dev/null
make coverage >/dev/null
bash ./func_tests/scripts/func_tests.sh
rm "$out" 2> /dev/null || true