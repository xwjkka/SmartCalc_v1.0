CC=gcc -std=c11 -D_GNU_SOURCE -g
CFLAGS=-c -Wall -Wextra -Werror
TEST_FLAGS=-lcheck -lm -lpthread
GCOV_FLAGS=--coverage -Wall -Wextra -Werror
SOURCES=$(wildcard s21_*.c)
OBJECTS=$(SOURCES:.c=.o)
TESTS_SOURCES=test_main.c $(wildcard tests/*.c)
TESTS_OBJECTS=$(TESTS_SOURCES:.c=.o)
EXECUTABLE=s21_calc

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS += -lrt -lsubunit
endif

all: install open

# sense:
# 	rm -rf */

install:
	rm -rf build
	make clean
	mkdir build
	cd ./build; cmake ../calc/CMakeLists.txt; cmake --build .

open:
	build/calc.app/Contents/MacOS/./calc 

uninstall:
	rm -rf build*

dvi:
	doxygen ./Doxygen
	open html/index.html

open_doc:
	open html/index.html

dist:
	cd ..; tar -cvf archive.tar src

$(EXECUTABLE): $(OBJECTS)
	$(CC) $^ -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

rebuild: clean all

s21_calc.a: $(OBJECTS)
	ar -rc s21_calc.a $(OBJECTS)
	ranlib s21_calc.a

style:
	clang-format -n *.c *.h tests/*.c tests/*.h

beautify:
	clang-format -i *.c *.h tests/*.c tests/*.h

clean: uninstall
	rm -rf $(OBJECTS) $(EXECUTABLE) $(TESTS_OBJECTS) *.o s21_calc.a *.gcov *.gcno *.gcda *.info test jeannakr *.dSYM

test: $(TESTS_OBJECTS) s21_calc.a
	$(CC) $^ -o test $(TEST_FLAGS)
	./test

gcov_report: $(TESTS_OBJECTS)
	$(CC) $(GCOV_FLAGS) $(TESTS_OBJECTS) $(SOURCES) $(TEST_FLAGS) -o test
	./test
	gcov *.gcno
	lcov -t "s21_calc" -o s21_calc.info -c -d . --rc lcov_coverage
	genhtml -o report s21_calc.info --rc lcov_coverage
	open report/index.html

leaks: test
	leaks -atExit -- ./test

valgrind: test
	valgrind --leak-check=full --leak-resolution=med ./test

jeannakr:
	$(CC) $(CFLAGS) $(SOURCES)
	./a.out
