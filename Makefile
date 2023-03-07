#
# Copyright (с) 2022 Team of School 21 students:
# gissurmo, danniell, koolaldu, torwyndl, yonnarge
#
# Team Leader: gissurmo@student.21-school.ru
#

NAME = s21_string.a
HEADER = s21_string.h
TEST = unit_test_s21_string
REPORT = GcovReport

CC = gcc
GCOVFLAGS = -fprofile-arcs -ftest-coverage
CFLAGS = -std=c11 -Wall -Werror -Wextra
OS = $(shell uname)
ifeq ($(OS), Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm
else
    CHECK_FLAGS = -lcheck
endif

# Основные функции библиотеки
SRCS_LIBS = s21_memchr.c	\
            s21_memcmp.c	\
            s21_memcpy.c	\
            s21_memset.c	\
            s21_memmove.c	\
            s21_strcat.c	\
            s21_strncat.c	\
            s21_strchr.c	\
            s21_strcmp.c	\
            s21_strncmp.c	\
            s21_strcpy.c	\
            s21_strncpy.c	\
            s21_strcspn.c	\
            s21_strpbrk.c	\
            s21_strrchr.c	\
            s21_strspn.c	\
            s21_strstr.c	\
            s21_strtok.c	\
            s21_strlen.c	\
            s21_strerror.c	\
            s21_sprintf.c

SRCS = $(SRCS_LIBS)

OBJS = $(SRCS:.c=.o)

all: s21_string.a

s21_string.a: $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

test: $(NAME)
	$(CC) $< $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	./$(TEST)

gcov_report:
	gcc $(GCOVFLAGS) $(TEST).c $(SRCS) $(CHECK_FLAGS) -o $(REPORT)
	chmod +x *
	./GcovReport
	lcov -t "$(REPORT)" -o $(REPORT).info -c -d .
	genhtml -o report $(REPORT).info
	rm -rf ./*.gcno ./*.gcda ./$(REPORT).*
	@echo Code coverage report generated. To view the report via web-browser, enter the command \"open ./report/index.html\"

check: $(NAME)
	@echo ---------------------CPPCHECK---------------------
	cppcheck *.h *.c
	@echo ---------------------CPPLINT----------------------
	cp ../materials/linters/CPPLINT.cfg CPPLINT.cfg
	python3 ../materials/linters/cpplint.py --extension=c *.c *.h
	rm CPPLINT.cfg
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no leaks --atExit -- ./$(TEST)

check_valgrind: $(NAME)
	@echo -------------------MEMORY_LEAKS-------------------
	$(CC) -g $(TEST).c $(NAME) $(CHECK_FLAGS) -o $(TEST)
	CK_FORK=no valgrind --leak-check=full -s ./$(TEST)

clean:
	rm -rf $(OBJS) ./GcovReport ./*.gcov ./*.gcno ./*.gcda ./report ./*.info ./*.dSYM ./$(TEST)

fclean: clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all test check check_valgrind clean fclean re
