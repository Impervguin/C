#!/bin/bash
GPI_DIR="./gpis"
DATA_DIR="./post/liners"
POST_DIR="./post"
GRAPH_DIR="./graphs"

# Собирает gpi файлы для линейно-кусочных графиков для каждого варианта исполняемого файла(все что лежит в DATA_DIR)
for f in "$DATA_DIR"/*; do
  fout="$GPI_DIR/line_$(echo "$f" | cut -d"/" -f4).gpi"
  echo "#!/usr/bin/gnuplot -persist" > $fout
  echo 'set title "Измерение времени сортировки в зависимости от количества элементов"' >> $fout
  echo 'set xlabel "Количество элементов, шт"' >> $fout
  echo 'set ylabel "Время, мкс"' >> $fout
  echo 'set grid' >> $fout
  echo 'set terminal svg size 1920, 1080 font "Helvetica, 23"' >> $fout
  echo set output \""$GRAPH_DIR/line_$(echo "$f" | cut -d"/" -f4).svg"\" >> $fout
  echo plot \"$f\" with linespoints >> $fout
done

# График со всеми линиями сразу
fout="$GPI_DIR/all_lines.gpi"
echo "#!/usr/bin/gnuplot -persist" > $fout
echo 'set title "Измерение времени сортировки в зависимости от количества элементов"' >> $fout
echo 'set xlabel "Количество элементов, шт"' >> $fout
echo 'set ylabel "Время, мкс"' >> $fout
echo 'set grid' >> $fout
echo 'set terminal svg size 1920, 1080 font "Helvetica, 23"' >> $fout
echo set output \""$GRAPH_DIR/all_lines.svg"\" >> $fout
echo "plot \\" >> $fout
for f in $DATA_DIR/*;do
  echo \"$f\" with linespoints, \\ >> $fout
done

# График с линиями с кешированием
fout="$GPI_DIR/all_cache.gpi"
echo "#!/usr/bin/gnuplot -persist" > $fout
echo 'set title "Измерение времени сортировки в зависимости от количества элементов"' >> $fout
echo 'set xlabel "Количество элементов, шт"' >> $fout
echo 'set ylabel "Время, мкс"' >> $fout
echo 'set grid' >> $fout
echo 'set terminal svg size 1920, 1080 font "Helvetica, 23"' >> $fout
echo set output \""$GRAPH_DIR/all_cache.svg"\" >> $fout
echo "plot \\" >> $fout
for f in $DATA_DIR/sort*cache_*;do
  echo \"$f\" with linespoints, \\ >> $fout
done
