#!/bin/bash

SUCCESS="\033[92m"
ERROR="\033[91m"
RESET="\033[0m"

bash clean.sh
bash build_release.sh
bash ./func_tests/scripts/func_tests.sh -v

out=$(mktemp)

bash clean.sh
bash build_debug_asan.sh
bash ./func_tests/scripts/func_tests.sh 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Address sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Address sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash build_debug_msan.sh
bash ./func_tests/scripts/func_tests.sh 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Memory sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Memory sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash build_debug_ubsan.sh
bash ./func_tests/scripts/func_tests.sh 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Undefined behavior sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Undefined behavior sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash collect_coverage.sh