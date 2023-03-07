/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strpbrk возвращает указатель на символ
 * в строке str1, соответствующий одному из символов
 * в строке str2, или NULL, если такого символа нет в строке.
 */
char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = S21_NULL;
    s21_size_t i = s21_strcspn(str1, str2);
    if (i < s21_strlen(str1))
        result = (char *)(str1 + i);
    return result;
}
