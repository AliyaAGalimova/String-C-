/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strncpy копирует только первые n байтов из строки src,
 * в массив, на который указывает dest. Строки не могут перекрываться,
 * и в результирующей строке dest должно быть достаточно места для копии.
 * Если в n байтах строки src нет нулевого байта, то строка результата
 * не будет заканчиваться символом '\0'. Если длина src меньше, чем n,
 * то остальное место в dest будет заполнено нулями.
 */
char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    unsigned int i = 0;
    for (; src[i] != '\0' && i < n ; i++) {
        dest[i] = src[i];
    }
    for (; i < n ; i++) {
        dest[i] = '\0';
    }
    return dest;
}
