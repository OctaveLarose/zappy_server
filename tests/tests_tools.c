/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "game/game.h"
#include "tools.h"

Test(buffer_t, tools)
{
    buffer_t game_log;

    game_log.len = 0;
    cr_assert(add_str_to_buffer("hello world", &game_log));
    cr_assert_str_eq("hello world", game_log.str);
    cr_assert(add_str_to_buffer("abc", &game_log));
    cr_assert(add_str_to_buffer("def", &game_log));
    cr_assert_str_eq("hello worldabcdef", game_log.str);
    cr_assert_eq(game_log.len, 17);
    reset_buffer(&game_log);
    cr_assert_eq(game_log.len, 0);
    cr_assert_eq(game_log.str[0], '\0');
}

Test(buffer_overflow, tools)
{
    buffer_t game_log;
    int len_too_long = MAX_CMD_LEN + 30;
    char too_long_str[len_too_long];

    game_log.len = 0;
    memset(too_long_str, 'A', len_too_long);
    cr_assert(!add_str_to_buffer(too_long_str, &game_log));
}

Test(array_tools, tools)
{
    char *arr1[] = {"abc", "def", "hello", NULL};
    char **arr2 = NULL;

    cr_assert_eq(get_array_size(arr1), 3);
    cr_assert_eq(get_array_size(arr2), 0);
}