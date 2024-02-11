CC := gcc
SRC := ./src
INC := ./inc
OUT := ./out
LIB := ./lib
UNIT := ./unit_tests
OUT_FILE := ./func_tests/out_file

Cflags := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -I$(INC)
Linkflags :=
Unitflags := -lcheck -lm -lpthread -lrt -lsubunit
# Unitflags := -lcheck -lm -lpthread -lrt
OBJflags := -I$(SRC) -c -fPIC

debug : clean
debug : Cflags += -g
debug : unit_tests.exe
  
debug_ubsan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=undefined
debug_ubsan : CC := clang
debug_ubsan : Linkflags := -fsanitize=undefined
debug_ubsan : clean unit_tests.exe

debug_asan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=address
debug_asan : CC := clang
debug_asan : Linkflags := -fsanitize=address
debug_asan : clean unit_tests.exe

debug_msan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=memory -fPIE
debug_msan : CC := clang
debug_msan : Linkflags := -fsanitize=memory -fPIE
debug_msan : clean app.exe unit_tests.exe

coverage : Cflags += --coverage
coverage : Linkflags := --coverage
coverage : clean unit_tests.exe

.PHONY : clean
clean:
	rm *.exe $(OUT)/* $(LIB)/* 2> /dev/null || true

unit_tests.exe : $(addprefix $(OUT)/, check_main.o fibonacci.o arr.o)
	$(CC) $(Linkflags) $^ -o $@ $(Unitflags)

$(LIB)/%.so : $(OUT)/%.o $(INC)/*.h
	mkdir $(LIB) 2> /dev/null || true
	$(CC) $(Cflags) -o $@ -shared $<

$(OUT)/%.o : $(SRC)/%.c $(INC)/*.h
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@

$(OUT)/check_%.o : $(UNIT)/check_%.c $(INC)/*.h $(UNIT)/check_*.c
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@

unit : unit_tests.exe
	./unit_tests.exe

.PHONY : test

test : 
	bash ./func_tests/scripts/test.sh

start : $(addprefix $(LIB)/, fibonacci.so arr.so)
	python3 main.py
