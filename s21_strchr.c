/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strchr возвращает указатель на местонахождение
 * первого совпадения с символом 'c' в строке str.
 * Завершающий символ '\0' учитывается.
 * Если символ не найден, возвращается NULL.
 */
char *s21_strchr(const char *str, int c) {
    return s21_memchr(str, c, s21_strlen(str) + 1);
}
