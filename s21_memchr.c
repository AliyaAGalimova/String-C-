/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_memchr ищет символ 'c' в первых n байтах
 * той области памяти, на которую указывает str.
 * Совпадение первого байта с 'c' (представленным как беззнаковый символ)
 * останавливает выполнение операции.
 */
void *s21_memchr(const void *str, int c, s21_size_t n) {
    unsigned char *p = (unsigned char *)str;
    unsigned char *result = S21_NULL;
    for (; n != 0; n--, p++) {
        if (*p == (unsigned char)c) {
            result = p;
            break;
        }
    }
    return (result);
}
