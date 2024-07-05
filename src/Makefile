DIRECTORY=.
SOURCES=$(filter-out controller.cc, $(wildcard *.cc))
HEADERS=$(wildcard *.h)
OBJ=$(SOURCES:.cc=.o)
LIB_NAME=s21_SmartCalc.a

LEXEMES_DIR=Lexemes
LEXEMES_SOURCES=$(wildcard $(LEXEMES_DIR)/*.cc)
LEXEMES_HEADERS=$(wildcard $(LEXEMES_DIR)/*.h)
LEXEMES_OBJ=$(LEXEMES_SOURCES:.cc=.o)

CC=g++
CFLAGS=-std=c++17
FLAG1=-I src
FLAG2=-c
OPEN=
TC_FLAGS=
LEAK_CHECK=
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	OPEN= xdg-open
    CC += -D LINUX -m64
	TC_FLAGS += -lcheck -lsubunit -lm -lrt -lpthread
	LEAK_CHECK +=CK_FORK=no valgrind --trace-children=yes --track-fds=yes --leak-check=yes --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind_log.txt ./test.out
endif
ifeq ($(UNAME_S),Darwin)
    CC += -D OSX
	TC_FLAGS += -lcheck -lm -lpthread
	LEAK_CHECK +=CK_FORK=no leaks -atExit -- ./test.out
	OPEN= open
endif

default: all

all: clean test $(LIB_NAME)

test: clean $(LIB_NAME)
	$(CC) $(CFLAGS) -lgtest -lgtest_main test.cc $(LIB_NAME) -o test.out $(TC_FLAGS)
	./test.out


$(LIB_NAME): $(HEADERS) $(OBJ) $(LEXEMES_HEADERS) $(LEXEMES_OBJ)
	ar rcs $(LIB_NAME) $(OBJ) $(LEXEMES_OBJ)
	ranlib $(LIB_NAME)

%.o: %.cc
	$(CC) $(FLAG1) $(CFLAGS) $(FLAG2) $< -o $@

clean:
	rm -rf ../build ../*.tgz *.a *.o ./Lexemes/*.o *.out *.txt *.info *.gcno *.gcda report *.cfg *.gcov

check:
	clang-format -style=google -i *.cc
	clang-format -style=google -i *.h
	clang-format -style=google -n *.cc
	clang-format -style=google -n *.h
	$(LEAK_CHECK)

dvi:
	$(OPEN) dvi.html

dist: clean
	mkdir -p ../build
	mkdir -p ../build/SmartCalc
	mkdir -p ../build/Lexemes
	cp ./SmartCalc/* ../build/SmartCalc
	cp ./Lexemes/* ../build/Lexemes
	cp ./*.cc ../build
	cp ./*.h ../build
	cp dvi.html ../build
	tar -cvzf ../SmartCalc.tgz Makefile ./SmartCalc/* ./Lexemes/* ./*.cc ./*.h dvi.html

install: dist
	@cd ../build/SmartCalc; qmake
	@make -C ../build/SmartCalc

uninstall:
	rm -rf ../build ../*.tgz