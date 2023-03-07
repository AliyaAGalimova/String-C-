/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_memset заполняет первые n байтов той области памяти,
 * на которую указывает s, постоянным байтом c.
 */
void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *s = str;
    while (n != 0) {
        *s = (unsigned char)c;
        n--;
        s++;
    }
    return str;
}
