CC := gcc
SRC := ./src
INC := ./inc
OUT := ./out
UNIT := ./unit_tests
OUT_FILE := ./func_tests/out_file

Cflags := -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-equal -Wfloat-conversion -I$(INC)
Linkflags :=
# Unitflags := -lcheck -lm -lpthread -lrt -lsubunit
Unitflags := -lcheck -lm -lpthread -lrt
OBJflags := -I$(SRC) -c

debug : clean
debug : Cflags += -g
debug : app.exe unit_tests.exe
debug : app.exe
  
debug_ubsan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=undefined
debug_ubsan : CC := clang
debug_ubsan : Linkflags := -fsanitize=undefined
debug_ubsan : clean app.exe unit_tests.exe

debug_asan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=address
debug_asan : CC := clang
debug_asan : Linkflags := -fsanitize=address
debug_asan : clean app.exe unit_tests.exe

debug_msan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=memory -fPIE
debug_msan : CC := clang
debug_msan : Linkflags := -fsanitize=memory -fPIE
debug_msan : clean app.exe unit_tests.exe

coverage : Cflags += --coverage
coverage : Linkflags := --coverage
coverage : clean app.exe unit_tests.exe

release : clean
release : app.exe

Release : app.exe

Debug : Cflags += -g
Debug : app.exe unit_tests.exe 

.PHONY : clean
clean:
	rm *.exe $(OUT)/* 2> /dev/null || true

app.exe : $(addprefix $(OUT)/, mat.o mat_op.o main.o)
	$(CC) $(Linkflags) $^ -o $@

unit_tests.exe : $(addprefix $(OUT)/, check_main.o mat.o mat_op.o)
	$(CC) $(Linkflags) $^ -o $@ $(Unitflags)

$(OUT)/%.o : $(SRC)/%.c $(INC)/*.h
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@

$(OUT)/check_%.o : $(UNIT)/check_%.c $(INC)/*.h
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@

$(OUT)/check_main.o : $(addprefix $(UNIT)/, check_main.c check_mat.c check_mat_op.c) $(INC)/*.h
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@
unit : unit_tests.exe
	./unit_tests.exe

.PHONY : test

test : 
	bash ./func_tests/scripts/test.sh
