/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strlen вычисляет длину строки str.
 * Завершающий символ '\0' не учитывается.
 */
s21_size_t s21_strlen(const char *str) {
    s21_size_t count = 0;
    while (*str != '\0') {
        str++;
        count++;
    }
    return count;
}
