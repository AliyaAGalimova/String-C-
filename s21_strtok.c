/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strtok разделяет строку str на токены.
 * Токеном называется ненулевая строка, состоящая из символов,
 * не встречающихся в строке delim. При первом вызове функции
 * необходимо указать строку sек в качестве первого аргумента.
 * В последующих вызовах в качестве первого аргумента нужно
 * использовать S21_NULL. Каждый вызов возвращает указатель
 * на следующий токен или NULL, если токенов больше
 * не обнаружено. Если в строке str нет символов
 * из строки delim, или строка delim - пустая, то функция
 * возвращает строку str.
 *
 * ОСТОРОЖНО!
 * Функция изменяет исходную строку.
 * Информация о разделителях теряется.
 */
char *s21_strtok(char *str, const char *delim) {
    static char *token = S21_NULL;
    char *result = S21_NULL;

    if (str == S21_NULL)
        str = token;

    str += s21_strspn(str, delim);
    token = str + s21_strcspn(str, delim);

    if (*str == '\0') {
        token = S21_NULL;
        result = S21_NULL;
    } else if (token[0] != '\0') {
        token[0] = '\0';
        token++;
        result = str;
    } else if (token[0] == '\0') {
        token = S21_NULL;
        result = str;
    }
    return result;
}
