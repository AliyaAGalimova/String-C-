/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strcpy копирует строку, на которую указывает src,
 * включая завершающий символ '\0', в массив, на который указывает dest.
 * Строки не могут перекрываться, и в результирующей
 * строке dest должно быть достаточно места для копии.
 */
char *s21_strcpy(char *dest, const char *src) {
    s21_memcpy(dest, src, s21_strlen(src) + 1);
    return dest;
}
