# Тесты для лабораторной номер 1

## Входные данные
Целые числа, с окончанием ввиде неверного ввода

## Выходные данные
Максимальное число подряд идущих одинаковых чисел

## Позитивные тесты

### Тесты сортировки

01 - Один элемент

02 - Два элемента, по возрастанию

03 - Два элемента, по убыванию

04 - Нечетное кол-во элементов, по убыванию

05 - Нечетное кол-во элементов, по возрастанию

06 - Нечетное кол-во элементов, случайный массив

07 - Четное кол-во элементов, по убыванию

08 - Четное кол-во элементов, по возрастанию

09 - Четное кол-во элементов, случайный массив

10 - Массив c одинаковыми элементами

### Тесты Фильтрации

11 - Случайный массив(хотя бы одно после фильтрации остается)

12 - Два элемента, где первый > второго

13 - Три элемента, где 3 < 2,  1 < 2 + 3

14 - Три элемента, где 3 < 2,  1 = 2 + 3

15 - Три элемента, где 3 < 2,  1 > 2 + 3

16 -  Три элемента, где 3 >= 2,  1 > 2 + 3

## Негативные тесты

### Тесты фильтрации

01 - Один элемент

02 - Все элементы одинаковые

03 - Массив, в котором при фильтрации не останется элементов

### Стандарстные тесты

04 - Пустой файл

05 - Строка вместо числа

06 - Пустая строка в файле

07 - Несуществующий файл
