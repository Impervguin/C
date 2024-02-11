import ctypes

# Библиотека для 1-го задания: создания массива фибоначчи
class FibonacciLib:
    def __init__(self, lib_way : str) -> OSError:
        self.lib = ctypes.CDLL(lib_way) # Открываем библиотеку
        # Получаем функцию и задаем её параметры
        self.fiblist = self.lib.fill_fibonacci_arr 
        self.fiblist.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t)
        self.fiblist.restype = ctypes.c_int
        return None
    
    # Функция заполнения массива числами фибоначи
    # count - количество чисел.
    def fibonacci_list(self, count : int) -> list:
        if (count <= 0):
            return []
        tmp = (ctypes.c_int * count)(*([0] * count))
        self.fiblist(tmp, count)
        return list(tmp)

# Библиотека для 2-го задания: Объединение массивов
class ArrLib:
    def __init__(self, lib_way : str) -> OSError:
        self.lib = ctypes.CDLL(lib_way) # Открываем библиотеку
        # Получаем функцию и задаем её параметры
        self.extendarr = self.lib.extend_w_uniq
        self.extendarr.argtypes = (ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.c_size_t, ctypes.POINTER(ctypes.c_int), ctypes.c_size_t, ctypes.POINTER(ctypes.c_size_t))
        self.extendarr.restype = ctypes.c_size_t
    
    # Функция объединения двух массивов, при этом в первый помещаются первые вхождения элементов 2-го
    # dst - Первый массив
    # src - Второй массив
    def extend_arr(self, dst : list, src : list) -> list:
        csrc = (ctypes.c_int * len(src))(*src)
        req_len = ctypes.c_size_t()
        # Подаем null в качестве первого массива и узнаем необходимый размер.
        self.extendarr(None, len(dst), len(dst), csrc, len(src), req_len) 
        # Создаем копию первого массива расширенного размера
        res = dst + [0] * (int(req_len.value) - len(dst)) 
        cres = (ctypes.c_int * len(res))(*res)
        # Объединяем со вторым
        self.extendarr(cres, len(dst), len(res), csrc, len(src), req_len)
        # Возвращаем объединенный массив
        return list(cres)

        


if __name__ == "__main__":
    flib = FibonacciLib()

    lst = flib.fibonacci_list(10)

    print(lst)

    arrlib = ArrLib()

    lst = arrlib.extend_arr([10], [10])

    print(lst)