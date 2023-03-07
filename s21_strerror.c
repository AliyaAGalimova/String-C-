/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include <stdlib.h>
#include "s21_string.h"
#include "s21_errors.h"

/*
 * Функция s21_abs возвращает абсолютное значение целого числа (величину этого числа по модулю).
 */
int s21_abs(int nbr);

/*
 * Функция s21_nbrlen вычисляет количество символов в целом числе с учётом знака.
 */
int s21_nbrlen(int nbr);

/*
 * Функция s21_itoa переводит целое число в символы, записывает их во вновь созданную строку и возвращает указатель на неё.
 * После использования функции необходимо очистить память по указателю.
 */
char *s21_itoa(int nbr);

/*
 * Функция add_errnum_to_description является вспомогательной для функции s21_strerror.
 * Она создаёт строку с числовым кодом ошибки с учётом пробела (пробела и двоеточия для MacOS).
 */
char *add_errnum_to_description(int errnum);

/*
 * Функция s21_strerror возвращает строку, описывающую код ошибки, переданный в аргументе errnum,
 * или сообщение о том, что ошибка неизвестна c выводом этого кода.
 * Для работы функции необходим файл s21_errors.h, содержащий описание ошибок.
 * Ошибки описаны для операционных систем MacOS и Linux.
 */
char *s21_strerror(int errnum) {
    char *result = (char *)calloc(80, sizeof(char));
    char *errors[] = DESCRIPTION_OF_ERRORS;
    char *tmp_add_ernum;

    if (0 <= errnum && errnum <= N_OF_ERRORS) {
        s21_strcpy(result, errors[errnum]);
    } else {
        // Если операционная система не MacOS и не Linux
        s21_strcpy(result,
                   "No error information");
#if defined(__APPLE__) && defined(__MACH__) || defined(__linux__)
        // Для операционных систем MacOS или Linux
        s21_strcpy(result, "Unknown error");
#endif
        tmp_add_ernum = add_errnum_to_description(errnum);
        s21_strcat(result, tmp_add_ernum);
        free(tmp_add_ernum);
    }
    return (result);
}

char *add_errnum_to_description(int errnum) {
    char *addition_part =
        (char *)calloc(s21_nbrlen(errnum) + 3, sizeof(char));
    char space[] = " \0\0";
    char *tmp_s21_itoa;

#if defined(__APPLE__) && defined(__MACH__)
    // Для операционной системы MacOS
    space[0] = ':';
    space[1] = ' ';
#endif

#if defined(__linux__)
    // Для операционной системы Linux
    space[0] = ' ';
#endif

    s21_strcpy(addition_part, space);
    tmp_s21_itoa = s21_itoa(errnum);
    s21_strcat(addition_part, tmp_s21_itoa);

    free(tmp_s21_itoa);
    return (addition_part);
}

char *s21_itoa(int nbr) {
    int sign = (nbr < 0) ? -1 : 1;
    int len = s21_nbrlen(nbr);
    char *str = (char *)calloc(len + 1, sizeof(char));

    str[len] = '\0';
    len = len - 1;
    while (len >= 0) {
        str[len] = '0' + s21_abs(nbr%10);
        nbr = (nbr/10);
        len--;
    }
    if (sign == -1)
        str[0] = '-';
    return (str);
}

int s21_nbrlen(int nbr) {
    int len = ((nbr <= 0) ? 1 : 0);
    while (nbr != 0) {
        nbr = nbr/10;
        len++;
    }
    return (len);
}

int s21_abs(int nbr) {
    return ((nbr < 0) ? -nbr : nbr);
}
