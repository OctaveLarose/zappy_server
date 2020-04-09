/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "circular_buffer.h"

Test(add_basic, c_buffer)
{
    c_buffer_t buffer;
    char buf[10];
    int len_buf = 6;
    char *ptr;

    init_c_buffer(&buffer);
    sprintf(buf, "abcdef");
    cr_assert_eq(buffer.nbr_bytes, 0);
    add_to_buffer(buf, &buffer);
    cr_assert_eq(buffer.nbr_bytes, len_buf);
    cr_assert_str_eq(buffer.buffer, "abcdef");
    ptr = read_from_buffer(&buffer);
    cr_assert_str_eq(ptr, "abcdef");
    cr_assert_eq(buffer.nbr_bytes, 0);
    cr_assert(is_buf_readable(&buffer) == false);
}

Test(add_overflow, c_buffer)
{
    c_buffer_t buffer;
    int len_too_long_buf = CIRCULAR_BUFFER_LEN + 30;
    char too_long_buf[len_too_long_buf];
    char *str = "abcdefghijklmnopqrstuvwxyz";
    char *ptr;

    init_c_buffer(&buffer);
    memset(too_long_buf, 'x', CIRCULAR_BUFFER_LEN + 30);
    strcpy(too_long_buf + CIRCULAR_BUFFER_LEN - 1, str);
    too_long_buf[CIRCULAR_BUFFER_LEN + 25] = 'x';
    cr_assert_eq(add_to_buffer(too_long_buf, &buffer), ADD_FAIL);
    cr_assert_eq(buffer.nbr_bytes, 0);
    cr_assert_eq(buffer.read_offset, 0);
    ptr = read_from_buffer(&buffer);
    cr_assert_eq(buffer.read_offset, 0);
    cr_assert_eq(ptr, NULL);
}

Test(add_overflow_two_parter, c_buffer)
{
    c_buffer_t buffer;
    int len_long_buf = CIRCULAR_BUFFER_LEN - 10;
    char long_buf[len_long_buf];
    char *str = "abcdefghijklmnopqrstuvwxyz";

    init_c_buffer(&buffer);
    memset(long_buf, 'x', CIRCULAR_BUFFER_LEN - 10);
    cr_assert_eq(add_to_buffer(long_buf, &buffer), CIRCULAR_BUFFER_LEN - 10);
    cr_assert_eq(add_to_buffer(str, &buffer), ADD_FAIL);
}

Test(repeated, c_buffer)
{
    c_buffer_t buffer;
    char *str = "hello world";
    char *double_str = "hello worldhello world";
    char *read;

    init_c_buffer(&buffer);
    cr_assert_eq(buffer.read_offset, 0);
    cr_assert_eq(buffer.write_offset, 0);
    cr_assert_eq(buffer.nbr_bytes, 0);
    for (int i = 0; i < CIRCULAR_BUFFER_LEN / 36; i++) {
        add_to_buffer(str, &buffer);
        read = read_from_buffer(&buffer);
        cr_assert_str_eq(read, str);
        add_to_buffer(str, &buffer);
        add_to_buffer(str, &buffer);
        cr_assert_eq(is_buf_readable(&buffer), true);
        read = read_from_buffer(&buffer);
        cr_assert_str_eq(read, double_str);
        cr_assert_eq(is_buf_readable(&buffer), false);
    }
}

Test(two_parter, c_buffer)
{
    c_buffer_t buffer;
    char big_buf[CIRCULAR_BUFFER_LEN - 15];
    char *read;
    char *alpha = "abcdefghijklmnopqrstuvwxyz";

    init_c_buffer(&buffer);
    memset(big_buf, 'A', CIRCULAR_BUFFER_LEN - 15);
    add_to_buffer(big_buf, &buffer);
    read = read_from_buffer(&buffer);
    for (int i = 0; i < CIRCULAR_BUFFER_LEN - 15; i++)
        cr_assert_eq(buffer.buffer[i], read[i]);
    add_to_buffer(alpha, &buffer);
    read = read_from_buffer(&buffer);
    cr_assert_str_eq(read, "abcdefghijkl");
    cr_assert_eq(buffer.buffer[CIRCULAR_BUFFER_LEN - 2], 'l');
    cr_assert_eq(is_buf_readable(&buffer), true);
    read = read_from_buffer(&buffer);
    cr_assert_str_eq(read, "mnopqrstuvwxyz");
    cr_assert_eq(is_buf_readable(&buffer), false);
    read = read_from_buffer(&buffer);
    cr_assert_eq(read, NULL);
}