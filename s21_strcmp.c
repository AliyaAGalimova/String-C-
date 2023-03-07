/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strcmp сравнивает две строки: str1 и str2.
 * Она возвращает целое число, которое меньше, больше нуля
 * или равно ему, если str1 соответственно меньше, больше
 * или равно str2.
 */
int s21_strcmp(const char *str1, const char *str2) {
    const char *bigger_str;
    if (s21_strlen(str1) > s21_strlen(str2))
        bigger_str = str1;
    else
        bigger_str = str2;
    return s21_memcmp(str1, str2, s21_strlen(bigger_str));
}
