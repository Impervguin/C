#!/bin/bash

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

# Константа с кодами оптимизаций
if [[ -z $OPTS ]]
then
  echo "OPTS is not set. (optimisation codes)"
  exit 1
fi


# Собирает исходники
bash build_apps.sh
echo "Apps builded"
# Собирает данные
bash update_data.sh
clear
echo "Done collecting data"
# Подготавливает данные (среднее, максимальное...)
python3 prepdata.py
echo "Prepared data"
# Собирает подготовленные данные в графики
python3 make_postproc.py
echo "Postprocessed data"
# Создаем gpi для графиков
bash line_graphs.sh
echo "GPI'S done"
bash get_graphs.sh
echo "Graphs done"