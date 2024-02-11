#!/bin/bash
APPS_DIR="./apps"
SRC_DIR="./src"

DIRS="./data ./post ./prep ./graphs ./gpis ./src ./apps"

for dir in $DIRS; do
  if ! [[ -d $dir ]]; then
    mkdir $dir
  fi
done
# Константа с максимальной размерностью матрицы (тесты выше обработаны не будут)
if [[ -z $MAXNUM ]]
then
  echo "MAXNUM is not set. (max number of elements in tests)"
  exit 1
fi
# Константа с кодами оптимизаций
if [[ -z $OPTS ]]
then
  echo "OPTS is not set. (optimisation codes)"
  exit 1
fi

for opt in $OPTS # для каждой оптимизации компилируем каждый исходник в папке исходников
do
  for app in "$SRC_DIR"/*.c
  do
    for BEST in -1 0 1
    do
      if [[ $BEST -eq -1 ]]; then
        beststr="w"
      elif [[ $BEST -eq 0 ]]; then
        beststr="r"
      else
        beststr="b"
      fi
      gcc -Dmaxnum="${MAXNUM}" -Dbest="${BEST}" -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -"$opt"\
        $app -o "$APPS_DIR"/"$(echo "$app" | cut -d"/" -f3 | cut -d"." -f1)_"$opt"_"$beststr"".exe
    done
  done
done