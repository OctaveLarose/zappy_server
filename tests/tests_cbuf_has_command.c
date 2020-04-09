/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "circular_buffer.h"

Test(has_command_normal, c_buffer)
{
    c_buffer_t buffer;

    init_c_buffer(&buffer);
    cr_assert_eq(has_command(&buffer), false);
    add_to_buffer("abc", &buffer);
    cr_assert_eq(has_command(&buffer), false);
    add_to_buffer("def\n", &buffer);
    cr_assert_eq(has_command(&buffer), true);
}

Test(has_command_circular, c_buffer)
{
    c_buffer_t buffer;
    int big_buf_len = CIRCULAR_BUFFER_LEN - 20;
    char big_buf[big_buf_len];

    init_c_buffer(&buffer);
    memset(big_buf, 'A', big_buf_len);
    big_buf[big_buf_len - 2] = '\n';
    big_buf[big_buf_len - 1] = '\0';
    cr_assert_eq(has_command(&buffer), false);
    for (int i = 0; i < (CIRCULAR_BUFFER_LEN - 30) / 6; i++)
        cr_assert(add_to_buffer("abcdef", &buffer) != ADD_FAIL);
    cr_assert(read_from_buffer(&buffer));
    cr_assert(add_to_buffer(big_buf, &buffer) != ADD_FAIL);
    cr_assert_eq(has_command(&buffer), true);
}