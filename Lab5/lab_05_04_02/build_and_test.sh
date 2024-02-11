#!/bin/bash

SUCCESS="\033[92m"
ERROR="\033[91m"
RESET="\033[0m"
KEYS="-t2b -b2t"
bash clean.sh
bash build_release.sh
bash build_b2t.sh
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh -v $KEYS # Если добавить в кавычки, то вся строка keys будет параметром

out=$(mktemp)

bash clean.sh
bash build_debug_asan.sh
bash build_b2t.sh
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Address sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Address sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash build_debug_msan.sh
bash build_b2t.sh
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Memory sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Memory sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash build_debug_ubsan.sh
bash build_b2t.sh
# shellcheck disable=SC2086
bash ./func_tests/scripts/func_tests.sh $KEYS 2> "$out"

if [[ -s "$out" ]]; then
  echo -e Undefined behavior sanitizer: "$ERROR"failed"$RESET"
  cat "$out"
else
  echo -e Undefined behavior sanitizer: "$SUCCESS"passed"$RESET"
fi

bash clean.sh
bash build_b2t.sh
bash collect_coverage.sh "$KEYS"