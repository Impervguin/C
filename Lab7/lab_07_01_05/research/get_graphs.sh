#!/bin/bash
GPI_DIR="./gpis"

# Собирает все графики по gpi-файлам
for gpi in $GPI_DIR/*.gpi; do
  gnuplot $gpi
done