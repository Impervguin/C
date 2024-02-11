CC := gcc

SRC := ./src
INC := ./inc
OUT := ./out
LIB := ./lib
UNIT := ./unit_tests
OUT_FILE := ./func_tests/out_file

Cflags := -std=c99 -Wall -Werror -Wextra -Wfloat-equal -Wfloat-conversion -I$(INC)
Linkflags :=
OBJflags := -I$(SRC) -c -fPIC

debug : clean
debug : Cflags += -g
debug : app.exe
  
debug_ubsan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=undefined
debug_ubsan : CC := clang
debug_ubsan : Linkflags := -fsanitize=undefined
debug_ubsan : clean app.exe

debug_asan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=address
debug_asan : CC := clang
debug_asan : Linkflags := -fsanitize=address
debug_asan : clean app.exe

debug_msan : Cflags += -fno-omit-frame-pointer -g -O0 -fsanitize=memory -fPIE
debug_msan : CC := clang
debug_msan : Linkflags := -fsanitize=memory -fPIE
debug_msan : clean app.exe

coverage : Cflags += --coverage
coverage : Linkflags := --coverage
coverage : clean app.exe 

release : clean
release : app.exe

Release : app.exe

Debug : Cflags += -g
Debug : app.exe  

.PHONY : clean
clean:
	rm *.exe $(OUT)/* $(LIB)/* 2> /dev/null || true


# Динамическая загрузка
app.exe : $(addprefix $(OUT)/, arr.o dynamic_main.o)
	$(CC) $(Linkflags) $^ -o app.exe -ldl

$(OUT)/%.o : $(SRC)/%.c $(INC)/*.h
	mkdir $(OUT) 2> /dev/null || true
	$(CC) $(Cflags) $(OBJflags) $< -o $@

.PHONY : test

test : 
	bash ./func_tests/scripts/test.sh