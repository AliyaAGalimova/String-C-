/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strcat добавляет к строке dest строку src,
 * перезаписывая символ `\0' в конце dest и добавляя к строке
 * символ окончания `\0'. Строки не могут перекрываться,
 * в строке dest должно хватать свободного места
 * для размещения объединенных строк.
 */
char *s21_strcat(char *dest, const char *src) {
    s21_strcpy(dest + s21_strlen(dest), src);
    return dest;
}
