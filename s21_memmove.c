/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include "s21_string.h"

/*
 * Функция s21_memmove копирует n байтов из области памяти src
 * в облать памяти dest. Области памяти могут перекрываться.
 */
void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    char *p_src = (char *)src;
    char *p_dest = dest;
    unsigned long int i;

    if (p_dest < p_src) {
        for (i = 0; i < n; i++) {
            p_dest[i] = p_src[i];
        }
    } else if (p_dest > p_src) {
        for (i = (n - (n != 0)); i > 0 ; i--) {
            p_dest[i] = p_src[i];
        }
        p_dest[0] = p_src[0];
    }
    return p_dest;
}
