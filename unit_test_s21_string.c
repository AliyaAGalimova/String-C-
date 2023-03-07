/*
 * Copyright (с) 2022 Team of School 21 students:
 * gissurmo, danniell, koolaldu, torwyndl, yonnarge
 *
 * Team Leader: gissurmo@student.21-school.ru
 */

#include <check.h>
#include <string.h>
#include <errno.h>
#include <wchar.h>
#include "s21_string.h"

START_TEST(test_s21_strncmp) {
    const char a[] = "ab";
    const char b[] = "abc";
    const char c[] = "123";
    const char d[] = "";
    ck_assert_int_eq(s21_strncmp(a, b, 0), 0);
    ck_assert_int_eq(s21_strncmp(a, b, 1), 0);
    ck_assert_int_eq(s21_strncmp(a, b, 2), 0);
    ck_assert_int_lt(s21_strncmp(a, b, 3), 0);
    ck_assert_int_gt(s21_strncmp(b, a, 3), 0);
    ck_assert_int_gt(s21_strncmp(a, c, 1), 0);
    ck_assert_int_gt(s21_strncmp(a, c, 3), 0);
    ck_assert_int_gt(s21_strncmp(a, d, 1), 0);
}
END_TEST

START_TEST(test_s21_memcmp) {
    char *ab = "ab";
    char *cd = "cd";
    ck_assert_int_eq(s21_memcmp(ab, ab, 3), 0);
    ck_assert_int_lt(s21_memcmp(ab, cd, 3), 0);
    ck_assert_int_eq(s21_memcmp(ab, "ab", 3), 0);
    ck_assert_int_gt(s21_memcmp(ab, "a", 3), 0);
    ck_assert_int_eq(s21_memcmp(ab, "a", 1), 0);
    ck_assert_int_eq(s21_memcmp(ab, "a", 0), 0);
    ck_assert_int_lt(s21_memcmp(ab, "b", 3), 0);
    ck_assert_int_gt(s21_memcmp(ab, "\0", 3), 0);
}
END_TEST

START_TEST(test_s21_strcmp) {
    const char a[] = "ab";
    const char b[] = "abc";
    const char c[] = "123";
    const char d[] = "";
    ck_assert_int_lt(s21_strcmp(a, b), 0);
    ck_assert_int_gt(s21_strcmp(b, a), 0);
    ck_assert_int_gt(s21_strcmp(a, c), 0);
    ck_assert_int_gt(s21_strcmp(c, d), 0);
    ck_assert_int_eq(s21_strcmp(a, a), 0);
    ck_assert_int_eq(s21_strcmp(d, d), 0);
}
END_TEST

START_TEST(test_s21_strlen) {
    ck_assert_uint_eq(s21_strlen(""), strlen(""));
    ck_assert_uint_eq(s21_strlen("a"), strlen("a"));
    ck_assert_uint_eq(s21_strlen("abc"), strlen("abc"));
    ck_assert_uint_eq(s21_strlen("ab\0c"), strlen("ab\0c"));
}
END_TEST

START_TEST(test_s21_memcpy) {
    char *s4 = "abcd";
    char *s3 = "xyz";
    char d3[3] = {0, 0, 0};
    char d5[5] = {0, 0, 0, 0, 0};

    ck_assert_str_eq(s21_memcpy(d3, s3, 0), memcpy(d3, s3, 0));
    ck_assert_str_eq(s21_memcpy(d5, s3, sizeof(char)*3), memcpy(d5, s3, sizeof(char)*3));
    ck_assert_str_eq(s21_memcpy(d5, s4, sizeof(char)*4), memcpy(d5, s4, sizeof(char)*4));
    ck_assert_str_eq(s21_memcpy(d5, s4, sizeof(char)*5), memcpy(d5, s4, sizeof(char)*5));
}
END_TEST

START_TEST(test_s21_memchr) {
    char *ab = "ab";
    ck_assert_str_eq(s21_memchr(ab, 'a', 1), memchr(ab, 'a', 1));
    ck_assert_str_eq(s21_memchr(ab, 'b', 2), memchr(ab, 'b', 2));
    ck_assert_str_eq(s21_memchr(ab, '\0', 3), memchr(ab, '\0', 3));
    ck_assert_str_eq(s21_memchr("aba", 'a', 4), memchr("aba", 'a', 4));
    ck_assert_str_eq(s21_memchr("ab\0a", 'a', 4), memchr("ab\0a", 'a', 4));

    ck_assert_ptr_eq(s21_memchr(ab, 'c', 3), memchr(ab, 'c', 3));
    ck_assert_ptr_eq(s21_memchr(ab, 'c', 4), memchr(ab, 'c', 4));
    ck_assert_ptr_eq(s21_memchr(ab, 'c', 0), memchr(ab, 'c', 0));
    ck_assert_ptr_eq(s21_memchr(ab, 'a', 0), memchr(ab, 'a', 0));
}
END_TEST

START_TEST(test_s21_memmove) {
    char s[] = "abcde";
    ck_assert_str_eq(s21_memmove(s, s, 0), memmove(s, s, 0));
    ck_assert_str_eq(s21_memmove(s, s, 2), memmove(s, s, 2));
    ck_assert_str_eq(s21_memmove(s, s + 1, 0), memmove(s, s + 1, 0));
    ck_assert_str_eq(s21_memmove(s + 1, s, 0), memmove(s + 1, s, 0));
    ck_assert_str_eq(s21_memmove(s, s + 2, 2), memmove(s, s + 2, 2));
    ck_assert_str_eq(s21_memmove(s + 2, s, 2), memmove(s + 2, s, 2));
    ck_assert_str_eq(s21_memmove(s, s + 3, 2), memmove(s, s + 3, 2));
    ck_assert_str_eq(s21_memmove(s + 3, s, 2), memmove(s + 3, s, 2));
}
END_TEST

START_TEST(test_s21_memset) {
    char a[] = "defg";
    char b[] = "defg";
    char c[] = "";
    ck_assert_str_eq(s21_memset(a, 'y', 3), memset(a, 'y', 3));
    ck_assert_str_eq(s21_memset(b, 'a', 5), memset(b, 'a', 5));
    ck_assert_str_eq(s21_memset(c, 'b', 1), memset(c, 'b', 1));
    ck_assert_str_eq(s21_memset(c, '\0', 1), memset(c, '\0', 1));
}
END_TEST

START_TEST(test_s21_strcpy) {
    char a[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};;
    const char b[] = "abc";
    const char c[] = "def";

    ck_assert_str_eq(s21_strcpy(a, b), strcpy(a, b));
    ck_assert_str_eq(s21_strcpy(a + 3, c), strcpy(a + 3, c));
    ck_assert_str_eq(s21_strcpy(a + 8, c + 2), strcpy(a + 8, c + 2));
}
END_TEST

START_TEST(test_s21_strncpy) {
    char s0[] = "\0";
    char s1[] = "1";
    char s3[] = "123";
    char d1[4] = {0, 0, 0, 0};
    char d2[4] = {0, 0, 0, 0};
    char d3[4] = {0, 0, 0, 0};
    char d4[4] = {0, 0, 0, 0};
    char d5[4] = {0, 0, 0, 0};

    ck_assert_str_eq(s21_strncpy(d1, s0, 3), strncpy(d1, s0, 3));
    ck_assert_str_eq(s21_strncpy(d2, s1, 3), strncpy(d2, s1, 3));
    ck_assert_str_eq(s21_strncpy(d3, s3, 0), strncpy(d3, s3, 0));
    ck_assert_str_eq(s21_strncpy(d4, s3, 1), strncpy(d4, s3, 1));
    ck_assert_str_eq(s21_strncpy(d5, s3, 3), strncpy(d5, s3, 3));
}
END_TEST

START_TEST(test_s21_strcat) {
    char s[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    const char ab[3] = "ab";
    char aba[10] = "ab\0a";
    ck_assert_str_eq(s21_strcat(s, ab), strcat(s, ab));
    ck_assert_str_eq(s21_strcat(s, "\0"), strcat(s, "\0"));
    ck_assert_str_eq(s21_strcat(s, ab), strcat(s, ab));
    ck_assert_str_eq(s21_strcat(aba, ab), strcat(aba, ab));
}
END_TEST

START_TEST(test_s21_strncat) {
    char d0[5] = {0, 0, 0, 0, 0};
    char d1[15] = {'1', 0};
    char s0[1] = {'\0'};
    char s3[3] = "ab";
    ck_assert_str_eq(s21_strncat(d0, s0, 0), strncat(d0, s0, 0));
    ck_assert_str_eq(s21_strncat(d0, s0, 1), strncat(d0, s0, 1));
    ck_assert_str_eq(s21_strncat(d0, s3, 0), strncat(d0, s3, 0));
    ck_assert_str_eq(s21_strncat(d0, s3, 3), strncat(d0, s3, 3));
    ck_assert_str_eq(s21_strncat(d1, s3, 0), strncat(d1, s3, 0));
    ck_assert_str_eq(s21_strncat(d1, s3, 1), strncat(d1, s3, 1));
    ck_assert_str_eq(s21_strncat(d1, s3, 2), strncat(d1, s3, 2));
    ck_assert_str_eq(s21_strncat(d1, s3, 3), strncat(d1, s3, 3));
}
END_TEST

START_TEST(test_s21_strchr) {
    char s1[] = "abc123";
    char s2[] = "123abc";
    char s3[] = "cba321";
    char s4[] = "1";
    char s5[] = "abc";
    char s6[] = "\0";
    char c = '1';
    char z = '\0';

    ck_assert_str_eq(s21_strchr(s1, c), strchr(s1, c));
    ck_assert_str_eq(s21_strchr(s2, c), strchr(s2, c));
    ck_assert_str_eq(s21_strchr(s3, c), strchr(s3, c));
    ck_assert_str_eq(s21_strchr(s4, c), strchr(s4, c));
    ck_assert_ptr_eq(s21_strchr(s5, c), strchr(s5, c));
    ck_assert_ptr_eq(s21_strchr(s6, c), strchr(s6, c));

    ck_assert_ptr_eq(s21_strchr(s5, z), strchr(s5, z));
    ck_assert_ptr_eq(s21_strchr(s6, z), strchr(s6, z));
}
END_TEST

START_TEST(test_s21_strcspn) {
    const char s1[] = "abc0123";
    const char s2[] = "456dss";
    const char s3[] = "789";
    const char s4[] = "abc";
    const char s5[] = "";
    const char num[] = "0123456789";

    ck_assert_int_eq(s21_strcspn(s1, num), strcspn(s1, num));
    ck_assert_int_eq(s21_strcspn(s2, num), strcspn(s2, num));
    ck_assert_int_eq(s21_strcspn(s3, num), strcspn(s3, num));
    ck_assert_int_eq(s21_strcspn(s4, num), strcspn(s4, num));
    ck_assert_int_eq(s21_strcspn(s5, num), strcspn(s5, num));
}
END_TEST

START_TEST(test_s21_strpbrk) {
    const char s1[] = "ab01c3";
    const char s2[] = "456dss";
    const char s3[] = "789";
    const char s4[] = "abc";
    const char s5[] = "";
    const char num[] = "0123456789";

    ck_assert_str_eq(s21_strpbrk(s1, num), strpbrk(s1, num));
    ck_assert_str_eq(s21_strpbrk(s2, num), strpbrk(s2, num));
    ck_assert_str_eq(s21_strpbrk(s3, num), strpbrk(s3, num));
    ck_assert_ptr_eq(s21_strpbrk(s4, num), strpbrk(s4, num));
    ck_assert_ptr_eq(s21_strpbrk(s5, num), strpbrk(s5, num));
    ck_assert_ptr_eq(s21_strpbrk(num, num), strpbrk(num, num));
}
END_TEST

START_TEST(test_s21_strspn) {
    const char s0[] = "a012d345";
    const char s1[] = "abc0";
    const char s2[] = "456def";
    const char s3[] = "789";
    const char s4[] = "abc";
    const char s5[] = "";
    const char num[] = "0123456789";

    ck_assert_int_eq(s21_strspn(s0, num), strspn(s0, num));
    ck_assert_int_eq(s21_strspn(s1, num), strspn(s1, num));
    ck_assert_int_eq(s21_strspn(s2, num), strspn(s2, num));
    ck_assert_int_eq(s21_strspn(s3, num), strspn(s3, num));
    ck_assert_int_eq(s21_strspn(s4, num), strspn(s4, num));
    ck_assert_int_eq(s21_strspn(s5, num), strspn(s5, num));
    ck_assert_int_eq(s21_strspn(s5, s5), strspn(s5, s5));
}
END_TEST

START_TEST(test_s21_strrchr) {
    const char a[] = "ab01c3";
    const char b[] = "ab01cd";
    const char c[] = "1abc";
    const char d[] = "";

    ck_assert_ptr_eq(s21_strrchr(a, '\0'), strrchr(a, '\0'));
    ck_assert_ptr_eq(s21_strrchr(d, '\0'), strrchr(d, '\0'));
    ck_assert_ptr_eq(s21_strrchr(b, '1'), strrchr(b, '1'));
    ck_assert_ptr_eq(s21_strrchr(c, '1'), strrchr(c, '1'));
    ck_assert_ptr_eq(s21_strrchr(d, '1'), strrchr(d, '1'));
}
END_TEST

START_TEST(test_s21_strstr) {
    const char s0[] = "";
    const char s1[] = "1ab";
    const char s2[] = "a1b";
    const char s3[] = "ab1";
    const char s4[] = "123ab";
    const char s5[] = "a123b";
    const char s6[] = "ab123";
    const char s4d[] = "12ab123";
    const char s5d[] = "a1123b123c";
    const char s7[] = "abc";
    const char s8[] = "123";
    const char n0[1] = {'\0'};
    const char n1[] = "1";
    const char n3[] = "123";

    ck_assert_str_eq(s21_strstr(s1, n1), strstr(s1, n1));
    ck_assert_str_eq(s21_strstr(s2, n1), strstr(s2, n1));
    ck_assert_str_eq(s21_strstr(s3, n1), strstr(s3, n1));
    ck_assert_str_eq(s21_strstr(s4, n3), strstr(s4, n3));
    ck_assert_str_eq(s21_strstr(s5, n3), strstr(s5, n3));
    ck_assert_str_eq(s21_strstr(s6, n3), strstr(s6, n3));
    ck_assert_str_eq(s21_strstr(s4d, n3), strstr(s4d, n3));
    ck_assert_str_eq(s21_strstr(s5d, n3), strstr(s5d, n3));
    ck_assert_str_eq(s21_strstr(s4, n0), strstr(s4, n0));
    ck_assert_str_eq(s21_strstr(s4, n1), strstr(s4, n1));
    ck_assert_str_eq(s21_strstr(s8, n3), strstr(s8, n3));

    ck_assert_ptr_eq(s21_strstr(s0, s0), strstr(s0, s0));
    ck_assert_ptr_eq(s21_strstr(s0, n0), strstr(s0, n0));
    ck_assert_ptr_eq(s21_strstr(s0, n1), strstr(s0, n1));
    ck_assert_ptr_eq(s21_strstr(s0, n3), strstr(s0, n3));
    ck_assert_ptr_eq(s21_strstr(s7, n3), strstr(s7, n3));
}
END_TEST

START_TEST(test_s21_strtok) {
    char s_func1[] = "ab,cd:efj//hn!!!";
    char s_orig1[] = "ab,cd:efj//hn!!!";
    char s_func2[] = "abc";
    char s_orig2[] = "abc";
    char s_func0[] = "";
    char s_orig0[] = "";
    char *t_func0_1, *t_func0_0;
    char *t_orig0_1, *t_orig0_0;
    char *t_func2_0_1, *t_func2_0_2;
    char *t_orig2_0_1, *t_orig2_0_2;
    char *t_func2_1_1, *t_func2_1_2;
    char *t_orig2_1_1, *t_orig2_1_2;
    char *t_func1_1_1, *t_func1_1_2, *t_func1_1_3, *t_func1_1_4, *t_func1_1_5;
    char *t_orig1_1_1, *t_orig1_1_2, *t_orig1_1_3, *t_orig1_1_4, *t_orig1_1_5;
    const char del1[] = ";:/?! ,";
    const char del0[] = "";

    t_func0_0 = s21_strtok(s_func0, del0);
    t_orig0_0 = strtok(s_orig0, del0);
    ck_assert_ptr_eq(t_func0_0, t_orig0_0);

    t_func0_1 = s21_strtok(s_func0, del1);
    t_orig0_1 = strtok(s_orig0, del1);
    ck_assert_ptr_eq(t_func0_1, t_orig0_1);

    t_func1_1_1 = s21_strtok(s_func1, del1);
    t_orig1_1_1 = strtok(s_orig1, del1);
    ck_assert_str_eq(t_func1_1_1, t_orig1_1_1);

    t_func1_1_2 = s21_strtok(NULL, del1);
    t_orig1_1_2 = strtok(NULL, del1);
    ck_assert_str_eq(t_func1_1_2, t_orig1_1_2);

    t_func1_1_3 = s21_strtok(NULL, del1);
    t_orig1_1_3 = strtok(NULL, del1);
    ck_assert_str_eq(t_func1_1_3, t_orig1_1_3);

    t_func1_1_4 = s21_strtok(NULL, del1);
    t_orig1_1_4 = strtok(NULL, del1);
    ck_assert_str_eq(t_func1_1_4, t_orig1_1_4);

    t_func1_1_5 = s21_strtok(NULL, del1);
    t_orig1_1_5 = strtok(NULL, del1);
    ck_assert_ptr_eq(t_func1_1_5, t_orig1_1_5);

    t_func2_1_1 = s21_strtok(s_func2, del0);
    t_orig2_1_1 = strtok(s_orig2, del0);
    ck_assert_str_eq(t_func2_1_1, t_orig2_1_1);

    t_func2_1_2 = s21_strtok(s_func2, del0);
    t_orig2_1_2 = strtok(s_orig2, del0);
    ck_assert_str_eq(t_func2_1_2, t_orig2_1_2);

    t_func2_0_1 = s21_strtok(s_func2, del0);
    t_orig2_0_1 = strtok(s_orig2, del0);
    ck_assert_str_eq(t_func2_0_1, t_orig2_0_1);

    t_func2_0_2 = s21_strtok(s_func2, del0);
    t_orig2_0_2 = strtok(s_orig2, del0);
    ck_assert_str_eq(t_func2_0_2, t_orig2_0_2);
}
END_TEST

START_TEST(test_s21_strerror) {
    char *tmp_s21_strerror;
    char *tmp_strerror;

#if defined(__APPLE__) && defined(__MACH__)
    for (int i = 0; i < 108; i++) {
        tmp_s21_strerror = s21_strerror(i);
        tmp_strerror = strerror(i);

        ck_assert_str_eq(tmp_s21_strerror, tmp_strerror);
        free(tmp_s21_strerror);
    }
#endif  // defined(__APPLE__) && defined(__MACH__)

#if defined(__linux__)
    for (int i = 0; i < 135; i++) {
        tmp_s21_strerror = s21_strerror(i);
        tmp_strerror = strerror(i);

        ck_assert_str_eq(tmp_s21_strerror, tmp_strerror);
        free(tmp_s21_strerror);
    }
#endif  // defined(__linux__)
}
END_TEST

START_TEST(test_s21_sprintf_1) {
    char str1[100];
    char str2[100];
    void *p = 0x0;
    unsigned int n1 = 0, n2 = 0;
    int r1 =
        sprintf(str1, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342,
                "aboba",
                'a', 123, 25.34, 4325.23434, 0.0000000123, 2.12345, 12345u,
                8342, 0.0000456, 1235, &n1, p, "hello my friend");
    int r2 =
        s21_sprintf(str2, "%d%o%s%c%i%e%f%E%g%u%x%G%X%n%p%%%s", 25, 342,
                    "aboba", 'a', 123, 25.34, 4325.23434,
                    0.0000000123, 2.12345, 12345u, 8342, 0.0000456, 1235,
                    &n2, p, "hello my friend");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(n1, n2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_2) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
    int r2 =
        s21_sprintf(str2, "%+-25.3d%25.15o%#10.f%015d", 252, 243, 256.34, 15);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_3) {
    char str1[100];
    char str2[100];
    int r1 = sprintf(str1, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234, 4567,
                     "HELLOMYDEARFRIEND");
    int r2 = s21_sprintf(str2, "%#+34.10g%#.10x%#15.1o%25.10s", 25.3456, 1234,
                         4567, "HELLOMYDEARFRIEND");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_4) {
    char str1[100];
    char str2[100];
    void *p = (void *)43252342;
    int r1 = sprintf(str1, "%#24.f%-15.20i%20p%020u", 43253242.4342, 4567899, p,
                     43252342u);
    int r2 = s21_sprintf(str2, "%#24.f%-15.20i%20p%020u", 43253242.4342, 4567899,
                         p, 43252342u);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
    char str3[50];
    char str4[100];
    int r3 = sprintf(str3, "%*.0f", 25, 25432.34345);
    int r4 = s21_sprintf(str4, "%*.0f", 25, 25432.34345);
    ck_assert_str_eq(str3, str4);
    ck_assert_int_eq(r3, r4);
}
END_TEST

START_TEST(test_s21_sprintf_5) {
    char s21_buffer[256] = { 0 };
    char buffer[256] = { 0 };
    char test1[20] = "Hell0 world\0";
    char test2[20] = "Hell0 world\n\0";
    char test3[10] = "a\n\0";
    char test4[10] = " \n\0";
    char test5[10] = " \0";
    char test6[10] = "\n\0";
    char test7[10] = "\0";
    s21_sprintf(s21_buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n',
                test2, '-', test3, test4, test5, test6, test7);
    sprintf(buffer, "%%%% %c %s %c%s %c %s %s %s %s %s", 'a', test1, '\n', test2,
            '-', test3, test4, test5, test6, test7);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_s21_sprintf_6) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer,
                "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
                -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
                (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    sprintf(buffer, "%-2i %+5i % 4i %2i %4d %d %15d %-+15d %22u %5u %4u %3u", 101,
            -210, -0, '0', 101, -210, -0, '0', (unsigned int)101,
            (unsigned int)210, (unsigned int)-0, (unsigned int)'0');
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_s21_sprintf_7) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};

    s21_sprintf(s21_buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
                (long int)125123123123, (short int)160, (unsigned short)101,
                (unsigned long)210, (short int)0, (long int)0, (short int)-25,
                (long int)-51);
    sprintf(buffer, "%- 5li %-5hi %12hu %-4lu %hi %li %hi %li",
            (long int)125123123123, (short int)160, (unsigned short)101,
            (unsigned long)210, (short int)0, (long int)0, (short int)-25,
            (long int)-51);
    ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(test_s21_sprintf_8) {
    char s21_buffer[256] = {0};
    char buffer[256] = {0};
    s21_sprintf(s21_buffer, "%-+6.4f %-2.2lf %5.5f %f %f", 100.0, 0.01, 0.10,
                -12.0, 0.00001);
    sprintf(buffer, "%-+6.4f %-2.2f %5.5f %f %f", 100.0, 0.01, 0.10, -12.0,
            0.00001);
    ck_assert_str_eq(s21_buffer, buffer);

    char s21_buffer2[256] = {0};
    char buffer2[256] = {0};
    s21_sprintf(s21_buffer2, "%lf %lf %lf %lf %lf %lf", 0.0/0.0, 1.0/0.0,
                0.0/1.0,
                -0.0/0.0, -1.0/0.0, -0.0/1.0);
    sprintf(buffer2, "%lf %lf %lf %lf %lf %lf", 0.0/0.0, 1.0/0.0, 0.0/1.0,
            -0.0/0.0, -1.0/0.0, -0.0/1.0);
    ck_assert_str_eq(s21_buffer2, buffer2);

    char s21_buffer3[256] = {0};
    char buffer3[256] = {0};
    s21_sprintf(s21_buffer3, "%lg %lG %#lg %le", 234243.234, 8427348.234,
                123.0, 155.2);
    sprintf(buffer3, "%lg %lG %#lg %le", 234243.234,
            8427348.234, 123.0, 155.2);
    ck_assert_str_eq(s21_buffer3, buffer3);
}
END_TEST

START_TEST(test_s21_sprintf_d) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    int r1 = sprintf(
        str1, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
        335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    int r2 = s21_sprintf(
        str2, "%-25.10d%-30.2d%10.12d%11d%*d%*.*d%+-25.*d%+10.2ld%-11.*hd", 253,
        335, 1234, 34, 10, 25, 5, 15, 345, 5, 666, 456789l, 5, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_i) {
    char str1[1000];
    char str2[1000];
    short h = 34;
    long l = 2353423523424;
    int r1 = sprintf(str1, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                     34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    int r2 =
        s21_sprintf(str2, "%+50.i%-10.20i%10.i%012i%*.*i%-10.*i%+10.1li%*.25hi",
                    34567, 225, 5230, 125, 10, 5, 456, 10, 377, l, 12, h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_c) {
    char str1[1000];
    char str2[1000];
    wchar_t c1 = 'T', c2 = 'Z';
    int r1 = sprintf(str1, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a', 'e',
                     'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    int r2 = s21_sprintf(str2, "%10c%-10c%25c%-30c%25c%*c%2c%*c%lc%-50lc", 'a',
                         'e', 'f', 'R', 'Q', 10, 'P', 'L', 20, 'x', c1, c2);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_E) {
    char str1[1000] = "";
    char str2[1000] = "";
    int r1 = sprintf(str1, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.10E",
                     3456.4325, 8, 23452.43242, 5, -0.05234, 25.432523432, 10,
                     2, 53242.4242, 10, 456789.43242, 25, 1111122222.34567899,
                     2345678.23453242);
    int r2 = s21_sprintf(
        str2, "%+-25.4E%25.*E%-*.10E%#02.E%*.*E%*.15E%*E%12.10E", 3456.4325, 8,
        23452.43242, 5, -0.05234, 25.432523432, 10, 2, 53242.4242, 10,
        456789.43242, 25, 1111122222.34567899, 2345678.23453242);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_f) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1, "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
        2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
        2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
        34567.43244);
    int r2 = s21_sprintf(
        str2, "%+-10.3f%+10.2f%15.10f%+*.6f%*.10f%-10.*f%25.*f%25.f%#+10.f%*.*f",
        2546.4324, 3452.4325, 5678.43256, 25, 456789.243242, 10, 3456789123.43245,
        2, 12345.6788, 1, 34.4325432, 4325678.43242, 34567.2345432, 10, 2,
        34567.43244);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_o) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 253;
    unsigned long l = 4325234324242l;
    int r1 = sprintf(str1, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                     12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    int r2 =
        s21_sprintf(str2, "%-25.10o%-10o%#-30.2o%#*.10o%#*.*o%25.*o%#.10ho%*lo",
                    12345, 6532, 43522, 10, 64342, 15, 2, 343, 6, 678, h, 10, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_x) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 345;
    unsigned long l = 52342353242l;
    int r1 = sprintf(str1,
                     "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%20.*"
                     "x%#10.*x%*.5hx%10.25lx",
                     235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                     8, 23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 = s21_sprintf(str2,
                         "%x%-25x%#10x%#-10x%#10.5x%-25.34x%#-10.2x%*.*x%#*.10x%"
                         "20.*x%#10.*x%*.5hx%10.25lx",
                         235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                         3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_X) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 234;
    unsigned long l = 4325243132l;
    int r1 = sprintf(str1,
                     "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%21.*X%"
                     "#12.*X%*.8hx%14.12lX",
                     235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15, 3452,
                     8, 23452, 10, 34254, 3, 33334, 10, h, l);
    int r2 = s21_sprintf(str2,
                         "%X%-10X%15X%#-15X%#20.3X%-30.12X%#-12.3X%*.*X%#*.15X%"
                         "21.*X%#12.*X%*.8hx%14.12lX",
                         235, 1234, 3456, 12345, 222234, 68432, 34567, 10, 15,
                         3452, 8, 23452, 10, 34254, 3, 33334, 10, h, l);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_u) {
    char str1[1000];
    char str2[1000];
    unsigned short h = 115;
    unsigned long l = 123325242342l;
    int r1 =
        sprintf(str1, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu",
                4321u, 34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u,
                20, 2432u, l, h);
    int r2 = s21_sprintf(
        str2, "%u%15u%-20u%010u%-15.10u%20.*u%*.*u%*.10u%-20.12lu%19hu", 4321u,
        34567u, 2342u, 12346u, 234542u, 10, 234523u, 10, 5, 2345u, 20, 2432u, l,
        h);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_s) {
    char str1[1000];
    char str2[1000];
    wchar_t s[10] = {'h', 'e', 'l', 'l', 'o'};
    int r1 = sprintf(str1, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                     "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                     "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    int r2 =
        s21_sprintf(str2, "%s%23s%-15s%10.s%15.2s%16.*s%*.*s%*s%15ls%15.3ls",
                    "aboba", "helloworld", "ABOBA", "ABOBBAAA", "AAABOBA", 10,
                    "QWERTY", 15, 4, "AAAAABOOOOOBAAA", 10, "ABOBAAAAA", s, s);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_p) {
    char str1[1000];
    char str2[1000];
    void *p1 = (void *)0x123456789;
    void *p2 = (void *)4325234;
    void *p3 = (void *)0x123f324b;
    void *p4 = (void *)432520;
    int r1 = sprintf(str1, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4, p2,
                     10, p3, p1, 10, p4);
    int r2 = s21_sprintf(str2, "%p%20p%-15p%10p%-15p%*p%10p%*p", p1, p2, p3, p4,
                         p2, 10, p3, p1, 10, p4);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_g) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
        2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
        2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
    int r2 = s21_sprintf(
        str2, "%g%23g%-10g%015g%#10.5g%0#15.10g%+10.6g%#*.g%-10.*g%+#25.8g",
        2345.4324, 23445.2342, 1234.234242, 3456.3424, 0.00001234, -324234.234,
        2345.4234, 5, 23456.4324, 9, 234567.43242, 0.0000034);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_G) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(
        str1,
        "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
        43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
        111.432534243243242, 4324.43242, 25, -3213.43242, 16,
        -43.43242353242342, 111.24324242, 25, 5, 0.000000342);
    int r2 = s21_sprintf(
        str2,
        "%G%25G%#-15G%017G%#05.2G%#010.16G%+#8.6G%*.8G%#-10.*G%+#12.16G%*.*G",
        43242.43242, 123432.43242, 0000.1234, -34252.43242, 1234.5,
        111.432534243243242, 4324.43242, 25, -3213.43242, 16,
        -43.43242353242342, 111.24324242, 25, 5, 0.000000342);
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

START_TEST(test_s21_sprintf_percent) {
    char str1[1000];
    char str2[1000];
    int r1 = sprintf(str1, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    int r2 = s21_sprintf(str2, "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%");
    ck_assert_str_eq(str1, str2);
    ck_assert_int_eq(r1, r2);
}
END_TEST

Suite *lib_suite_create(void) {
    Suite *suite_s21_string = suite_create("Suite_of_test_s21_string");
    TCase *tc_core_s21_string = tcase_create("Core_of_test_s21_string");

    tcase_add_test(tc_core_s21_string, test_s21_strlen);
    tcase_add_test(tc_core_s21_string, test_s21_memcpy);
    tcase_add_test(tc_core_s21_string, test_s21_memchr);
    tcase_add_test(tc_core_s21_string, test_s21_memcmp);
    tcase_add_test(tc_core_s21_string, test_s21_memmove);
    tcase_add_test(tc_core_s21_string, test_s21_memset);
    tcase_add_test(tc_core_s21_string, test_s21_strcpy);
    tcase_add_test(tc_core_s21_string, test_s21_strncpy);
    tcase_add_test(tc_core_s21_string, test_s21_strcat);
    tcase_add_test(tc_core_s21_string, test_s21_strncat);
    tcase_add_test(tc_core_s21_string, test_s21_strchr);
    tcase_add_test(tc_core_s21_string, test_s21_strcmp);
    tcase_add_test(tc_core_s21_string, test_s21_strncmp);
    tcase_add_test(tc_core_s21_string, test_s21_strcspn);
    tcase_add_test(tc_core_s21_string, test_s21_strpbrk);
    tcase_add_test(tc_core_s21_string, test_s21_strrchr);
    tcase_add_test(tc_core_s21_string, test_s21_strspn);
    tcase_add_test(tc_core_s21_string, test_s21_strstr);
    tcase_add_test(tc_core_s21_string, test_s21_strtok);
    tcase_add_test(tc_core_s21_string, test_s21_strerror);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_1);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_2);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_3);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_4);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_5);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_6);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_7);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_8);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_d);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_i);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_c);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_E);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_f);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_o);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_x);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_X);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_u);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_s);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_p);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_g);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_G);
    tcase_add_test(tc_core_s21_string, test_s21_sprintf_percent);

    suite_add_tcase(suite_s21_string, tc_core_s21_string);

    return suite_s21_string;
}

int main(void) {
    int failed_counter;
    Suite *suite = lib_suite_create();
    SRunner *suite_runner = srunner_create(suite);

    srunner_run_all(suite_runner, CK_NORMAL);
    failed_counter = srunner_ntests_failed(suite_runner);
    srunner_free(suite_runner);

    return (failed_counter == 0 ? EXIT_SUCCESS : EXIT_FAILURE);
}



