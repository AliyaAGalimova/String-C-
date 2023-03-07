/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strrchr возвращает указатель на местонахождение
 * последнего совпадения с символом c в строке str.
 * Завершающий символ '\0' учитывается.
 * Если символ не найден, возвращается NULL.
 */
char *s21_strrchr(const char *s, int c) {
    char *result = S21_NULL;
    int i = s21_strlen(s);
    for (; i >= 0; i--) {
        if ((char)c == s[i]) {
            result = (char *)(s + i);
            break;
        }
    }
    return result;
}
