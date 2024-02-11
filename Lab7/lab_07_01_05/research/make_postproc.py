import os
import re
from math import log
PREP_DIR = "./prep"
POST_DIR = "./post"

# Функция, которая читает подготовленные данные из файла в словарь
def read_prep(file) -> dict:
    d = dict()
    for line in file.readlines():
        parts = line.strip().split("=")
        if len(parts) == 2:
            d[parts[0]] = parts[1]
    return d

# Собирает таблицы для всех линейных графиков
line_reg = "[a-z0-9]*_O[0123s]_[br]_[0-9]*"
line_dir = "liners"
line_graphs = dict() # Хранит данные по всем таблицам графиков
# Струтура {название графика - {Количество элементов - {[столбцы таблицы начиная со 2-го]}}}
for f in [i for i in os.listdir(PREP_DIR) if re.match(line_reg, i)]:
    name, opt, arr_type, n = f.split("_")  # Получение составных частей имени
    typ = f"{name}_{opt}_{arr_type}"  # Тип графика(имя файла и оптимизация)
    if typ not in line_graphs:
        line_graphs[typ] = dict()  # Если такого графика не было до этого создает

    with open(os.path.join(PREP_DIR, f), "r") as fin:
        d = read_prep(fin)  # Считывает подготовленные данные
        if len(d) != 0:
            line_graphs[typ][n] = [d["average"], d["sigma"]]  # Записывает столбцы таблицы в словарь
# print(line_graphs)

tables = dict()
for name in line_graphs.keys():
    na, opt, t = name.split("_")
    if f"{opt}_{t}" not in tables:
        tables[f"{opt}_{t}"] = dict()
    tables[f"{opt}_{t}"][na] = line_graphs[name]

print(tables)
for name in tables:  # Для всех графиков записывает таблицу в файл
    with open(os.path.join(POST_DIR, line_dir, name), "w") as fout:
        fout.write("# Data columns: N_ELEM AV_TIME RSE AV_TIME RSE diff\n")
        for n in sorted(tables[name]['mysort'], key=lambda x: int(x)):  # Записывает таблицу в файл
            fout.write("| " + " | ".join([n] + tables[name]['mysort'][n] + tables[name]['qsort'][n] + [f"{float(tables[name]['mysort'][n][0])/float(tables[name]['qsort'][n][0]):.2f}"]) + " |" + '\n')


# graph_dir = "lns"
# reg = "[a-z0-9]*_O2_[0-9]*"
# vals = dict()
# for f in [i for i in os.listdir(PREP_DIR) if re.match(reg, i)]:
#     name, opt, n = f.split("_")
#     typ = f"{name}_{opt}"
#     if typ not in vals:
#         vals[typ] = dict()

#     with open(os.path.join(PREP_DIR, f), "r") as fin:
#         d = read_prep(fin)
#         if len(d) != 0:
#             vals[typ][n] = [d["average"], d["sigma"]]
# # print(vals)
# for name in vals:
#     n_s = sorted(vals[name], key=lambda x: int(x))
#     for i in range(len(n_s) - 1):
#         n1 = n_s[i]
#         n2 = n_s[i + 1]
#         lnn1 = log(int(n1))
#         lnn2 = log(int(n2))
#         lnt1 = log(float(vals[name][n1][0]))
#         lnt2 = log(float(vals[name][n2][0]))
#         val = f"{(lnt2 - lnt1) / (lnn2 - lnn1):.3f}"
#         vals[name][n1].append(val)


# for name in vals:
#     with open(os.path.join(POST_DIR, graph_dir, name), "w") as fout:
#         fout.write("# Data columns: N_ELEM AV_TIME RSE LN_VAL\n")
#         for n in sorted(vals[name], key=lambda x: int(x)):
#             fout.write(" ".join([n] + [str(i)for i in vals[name][n]]) + '\n')
