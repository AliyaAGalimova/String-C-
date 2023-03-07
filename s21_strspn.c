/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strspn вычисляет длину начального сегмента
 * строки str1, состоящего только из символов строки str2.
 */
/*
s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t i = 0;
    for (; str1[i]; i++) {
        if (s21_strchr(str2, str1[i]) == 0)
            break;
    }
    return i;
}
*/

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t i = 0;
    if (str1 != S21_NULL) {
        for (; str1[i]; i++) {
            if (s21_strchr(str2, str1[i]) == 0)
                break;
        }
    }
    return i;
}
