import os
import statistics
import math as m
DATA_PATH = "./data"
PREP_PATH = "./prep"


prep_data = dict() # Обработанные данные
for f in os.listdir(DATA_PATH): # Файл с данными по запускам
    prep_data.clear()
    with open(os.path.join(DATA_PATH, f), "r") as fin:
        lst = [int(line.strip()) for line in fin.readlines() if line.strip("\n ").isdecimal()]

    if (len(lst) != 0):
        av = sum(lst) / len(lst)  # Среднее по файлу
        prep_data["average"] = f"{sum(lst) / len(lst):.2f}"  # Среднее по файлу
        lst.sort()
        prep_data["max"] = lst[-1]  # Максимальное по файлу
        prep_data["min"] = lst[0]  # Минимальное по файлу
        quart = statistics.quantiles(lst, n=4)  # Квартели
        for i in range(len(quart)):
            prep_data[f"quart{i + 1}"] = int(quart[i])  # Квартели
        s = (sum([(lst[i] - av) ** 2 for i in range(len(lst))]) / (len(lst) - 1)) ** 0.5  # Средняя квадратичная ошибка
        # Относительная стандартная ошибка среднего
        prep_data["sigma"] = f"{s / (len(lst)) ** 0.5 / av * 100:.2f}" if av != 0 else "-"

    with open(os.path.join(PREP_PATH, os.path.splitext(f)[0]), "w") as fout:
        for name in prep_data.keys():
            fout.write(f"{name}={prep_data[name]}\n")  # Записывает все найденные значения для файла
