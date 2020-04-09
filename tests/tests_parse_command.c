/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "network/server.h"
#include "macros.h"

void redirect_all_std(void);

Test(normal, parse_command)
{
    c_buffer_t buf;
    char commands[MAX_COMMANDS][MAX_CMD_LEN];

    for (int i = 0; i < MAX_COMMANDS; i++)
        memset(commands[i], 0, MAX_CMD_LEN);
    init_c_buffer(&buf);
    cr_assert(!parse_command(&buf, commands));
    cr_assert_eq(buf.buffer[0], 0);
    cr_assert_neq(add_to_buffer("hello\nworld\n!!\n", &buf), ADD_FAIL);
    cr_assert(parse_command(&buf, commands));
    cr_assert_str_eq(commands[0], "hello");
    cr_assert_str_eq(commands[1], "world");
    cr_assert_str_eq(commands[2], "!!");
    cr_assert_str_eq(commands[3], "");
}

Test(not_done, parse_command)
{
    c_buffer_t buf;
    char commands[MAX_COMMANDS][MAX_CMD_LEN];
    int len_long_buf = MAX_CMD_LEN - 10;
    char long_buffer[len_long_buf];

    for (int i = 0; i < MAX_COMMANDS; i++)
        memset(commands[i], 0, MAX_CMD_LEN);
    init_c_buffer(&buf);
    memset(long_buffer, 'A', len_long_buf);
    cr_assert(add_to_buffer(long_buffer, &buf));
    cr_assert_neq(read_from_buffer(&buf), NULL);
    cr_assert_neq(add_to_buffer("this is a long sentence", &buf), ADD_FAIL);
    commands[0][0] = 'A';
    cr_assert(parse_command(&buf, commands));
    cr_assert_str_eq(commands[1], "this is a long sentence");
    cr_assert_str_eq(commands[2], "");
}

Test(normal, remove_endline, .init=redirect_all_std)
{
    char *str = strdup("Helloo");
    char *str2 = strdup("What's up\nGuys");

    cr_assert(str && str2);
    cr_assert(!remove_endline_from_command(str));
    cr_assert(remove_endline_from_command(str2));
}