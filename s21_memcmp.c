/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_memcmp сравнивает первые n байтов областей памяти
 * str1 и str2. Функция возвращает целое число.
 * Число будет больше нуля, если s1 больше s2.
 * Число будет меньше нуля, если s1 меньше s2.
 * При равенстве строк (и по длине и по составу) функция вернёт ноль.
 */
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *p1 = str1, *p2 = str2;
    int result = 0;
    for (; n != 0; n--, p1++, p2++) {
        if (*p1 != *p2) {
            result = *p1 - *p2;
            break;
        }
    }
    return (result);
}
