#!/bin/bash
APPS_DIR="./apps"
DATA_DIR="./data"

# Размеры матриц для сбора данных
if [[ -z $MS_SIZES ]];
then
  echo "MS_SIZES not set. (sizes of array to be tested on (cannot be higher than MAXNUM))"
  exit 1
fi
# Количество тестов для каждого файла
if [[ -z $TEST_COUNT ]];
then
  echo "TEST_COUNT not set. (count of tests on every size)"
  exit 1
fi
# Константа с максимальной размерностью матрицы (тесты выше обработаны не будут)
if [[ -z $MAXNUM ]]
then
  echo "MAXNUM is not set. (max number of elements in tests)"
  exit 1
fi

for app in  $APPS_DIR/*.exe
do
  for size in $MS_SIZES
  do
    if [[ $size -lt $MAXNUM ]];
    then
      c=0
      file="$DATA_DIR/$(echo "$app" | cut -d"/" -f3 | cut -d. -f1)_$size.txt"
      while [[ $c -lt $TEST_COUNT ]];
      do
        echo $file $c
        $app "$size" >> $file
        c=$((c+1))

      done
    fi
  done
done