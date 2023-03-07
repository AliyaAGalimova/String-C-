/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_memcpy копирует n байтов из области памяти src
 * в область памяти dest. Области памяти НЕ МОГУТ пересекаться.
 * Используйте s21_memmove, если области памяти перекрываются.
 */
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    char *dp = dest;
    const char *sp = src;
    while (n != 0) {
        *dp = *sp;
        dp++;
        sp++;
        n--;
    }
    return dest;
}
