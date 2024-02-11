import sys
from PyQt5.QtWidgets import QMainWindow, QApplication
from pyfiles.ui import Ui_MainWindow
import pyfiles.funcs as funcs

class MyMainWindow(QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        
        self.fibonacciButton.clicked.connect(self.fibonacci_generate)
        self.arrButton.clicked.connect(self.arr_generate)
    
    
    def fibonacci_generate(self):
        try:
            fiblib = funcs.FibonacciLib(self.fiblibEdit.text().strip())
        except OSError as err:
            self.fibonacciOut.setText("Не удалось открыть библиотеку.")
            return

        count = self.fibonacciNum.value()
        lst = fiblib.fibonacci_list(count)
        if (len(lst) == 0):
            self.fibonacciOut.setText("Пустой массив.")
        else:
            self.fibonacciOut.setText(" ".join([str(elem) for elem in lst]))
    
    def arr_generate(self):
        try:
            arrlib = funcs.ArrLib(self.arrlibEdit.text().strip())
        except OSError as err:
            self.arrresfield.setText("Не удалось открыть библиотеку.")
            return
        
        try :
            src = [int(el) for el in self.arr1field.toPlainText().split()]
        except BaseException:
            self.arrresfield.setText("Некорректный ввод 1-го массива.")
            return
        
        try :
            dst = [int(el) for el in self.arr2field.toPlainText().split()]
        except BaseException:
            self.arrresfield.setText("Некорректный ввод 2-го массива.")
            return
        lst = arrlib.extend_arr(dst, src)

        if (len(lst) == 0):
            self.arrresfield.setText("Пустой массив.")
        else:
            self.arrresfield.setText(" ".join([str(elem) for elem in lst]))


if __name__ == "__main__":
    app = QApplication(sys.argv)
    wind = MyMainWindow()
    wind.show()
    sys.exit(app.exec_())