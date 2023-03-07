/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strncmp сравнивает первые n символов
 * строк str1 и str2. Она возвращает целое число,
 * которое меньше, больше нуля или равно ему,
 * если str1 соответственно меньше, больше или равно str2.
 */
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    return s21_memcmp(str1, str2, n);
}
