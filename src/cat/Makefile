CC=gcc
CFLAG= -Wall -Werror -Wextra

all: clean s21_cat 

s21_cat: 
	$(CC) $(CFLAG) s21_cat.c cat_s21.c -o s21_cat

test:
	bash test_func_cat.sh

style:
	clang-format -style=Google -n -Werror *.c

clean:
	rm -f s21_cat
	rm -f *.o

rebuild: all