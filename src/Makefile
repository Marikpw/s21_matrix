CFLAGS =  -Wall -Werror -Wextra -std=c11
GFLAGS = -fprofile-arcs -ftest-coverage
FILES = s21_matrix.c
LIBS = -L. -lcheck -lm -lsubunit

all: test

test: s21_matrix.a tests.c $(FILES)
	gcc $(CFLAGS) -c $(FILES)
	gcc $(CFLAGS) -c tests.c
	gcc $(CFLAGS) *.o -o tests $(LIBS) s21_matrix.a
	./tests

s21_matrix.a: $(FILES)
	gcc $(CFLAGS) -c $(FILES)
	ar crs s21_matrix.a *.o

gcov_report: $(FILES) tests.c
	gcc $(CFLAGS) $(GFLAGS) -c $(FILES)
	gcc $(CFLAGS) -c tests.c
	gcc $(GFLAGS) *.o -o tests $(LIBS)
	./tests
	lcov -t "a.out" -o REPORT.info -c -d .
	genhtml -o html REPORT.info
	open html/index.html
	
rebuild:
	make clean
	make test

clean:
	rm -f tests ./*.o ./*.a report *.gcda *.gcno *info 
	rm -rf html

check:
	clang-format -style=Google -n $(FILES) *.h tests.c

clang:
	clang-format -style=Google -i $(FILES) *.h tests.c
