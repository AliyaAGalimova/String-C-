/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "s21_errors.h"

#define S21_NULL ((void *)0)

typedef long unsigned s21_size_t;

typedef struct Format {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_sharp;
  int flag_zero;
  int flag_mistake;
  int width;
  int allowance;
  char len;
  char spec;
} FORMAT;

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

int s21_sscanf(const char *str, const char *format, ...);
char *s21_string_trainer(char *str, char *string, char *buffer_string,
                         int buffer_length, va_list args, int is_ignoring,
                         int width, char length, char specifier,
                         int *is_continue, int *result);
char *s21_string_to_octanari(char *string, unsigned long long int *variable,
                             int width, int is_width_cutted);
char *s21_string_to_hexx(char *string, unsigned long long int *variable,
                         int width, int is_width_cutted);
char *s21_string_to_denary(char *string, unsigned long long int *variable,
                           int width, int is_width_cutted);
char *s21_d_trainer(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_o_trainer(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_x_trainer(char *string, va_list args, int width, char length, char specifier,
                    int is_ignoring, int *is_continue, int *result);
char *s21_u_trainer(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_i_trainer(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_f_trainer(char *string, va_list args, int width, char length, int is_ignoring,
                    int *is_continue, int *result);
char *s21_n_trainer(char *string, char *str, char *buffer_string, va_list args, char length, int is_ignoring);
char *s21_c_trainer(char *string, va_list args, char length, int is_ignoring);
char *s21_s_trainer(char *string, va_list args, int width, char length, int is_ignoring);
void write_to_varic(va_list args, unsigned long long int *variable_pointer, char length);
void write_to_unsigned_varic(va_list args, unsigned long long int *variable_pointer, char length);

int s21_sprintf(char *str, const char *format, ...);
void s21_set_flag(FORMAT *FFormat, const char *format);
char *specifier(char *str, s21_size_t *str_len, FORMAT *FFormat,
                va_list *argList);
char *s21_str_to_int(const char *format, int *number, va_list *argList);
char *s21_reverse_str(char *str);

void s21_n_to_s(s21_size_t const *str_len, va_list *argList);
char *s21_proc_to_p(char *str, FORMAT *FFormat);
char *s21_p_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_f_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_e_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_g_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_s_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_c_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_u_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_d_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_o_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_x_to_s(char *str, va_list *argList, FORMAT *FFormat);
char *s21_lf_to_str(char *str, long double number, FORMAT *FFormat);
char *s21_leE_to_str(char *str, long double number, FORMAT *FFormat);
char *s21_lgG_to_str(char *str, long double number, FORMAT *FFormat);

char *wch_to_str(char *str, wchar_t *wstr, s21_size_t len);
char *s21_lf_width_flag(char *str, FORMAT *FFormat);
char *s21_ll_width_flag(char *str, FORMAT *FFormat);
char *s21_sign_flag(char *str, FORMAT *FFormat);
char *s21_ll_allowance(char *str, FORMAT *FFormat);
char *s21_ll_to_str(char *str, long long number);
char *s21_ul_to_str(char *str, unsigned long long number);
char *s21_ol_to_str(char *str, unsigned long long number, int prefix);
char *s21_hl_to_str(char *str, unsigned long long number, FORMAT *FFormat);
char *s21_ld_to_a(char *str, long double number, FORMAT *FFormat);
char *d_class_to_str(char *str, long double x, int allowance);
long double s21_round(long double x, int allowance);

#endif  //  SRC_S21_STRING_H_
