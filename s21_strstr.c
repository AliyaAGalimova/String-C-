/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_strstr ищет первое вхождение подстроки needle
 * в строке haystack. Функция возвращают указатель на начало
 * подстроки, или NULL, если подстрока не найдена.
 */
char *s21_strstr(const char *haystack, const char *needle) {
    const char *p_haystack = haystack;
    const char *s1, *s2;
    char *result = S21_NULL;

    if (!*needle)
        result = (char *)haystack;

    while (*p_haystack && !result) {
        s1 = p_haystack;
        s2 = needle;
        while (*s1 && *s2 && !(*s1 - *s2))
            s1++, s2++;
        if (!*s2)
            result = (char *)p_haystack;
        p_haystack++;
    }
    return result;
}
