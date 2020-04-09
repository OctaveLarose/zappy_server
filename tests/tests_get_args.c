/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "arg_holder.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(normal, get_args)
{
    int ac = 15;
    char *av[] = {"./server", "-p", "123", "-x", "100", "-y", "200", \
"-n", "name1", "name2", "name3", "-c", "34", "-f", "42"};
    arg_holder_t *hldr;

    hldr = get_args(ac, av);
    cr_assert(hldr);
    cr_assert_eq(hldr->port, 123);
    cr_assert_eq(hldr->height, 200);
    cr_assert_eq(hldr->width, 100);
    cr_assert_eq(hldr->clients_nbr, 34);
    cr_assert_eq(hldr->freq, 42);
    cr_assert_str_eq(hldr->names[0], "name1");
    cr_assert_str_eq(hldr->names[1], "name2");
    cr_assert_str_eq(hldr->names[2], "name3");
    cr_assert_eq(hldr->names[3], NULL);
    free_arg_holder(hldr);
}

Test(no_args, get_args, .init=redirect_all_std)
{
    int ac = 1;
    char *av[] = {"./server"};
    arg_holder_t *hldr;

    hldr = get_args(ac, av);
    cr_assert(!hldr);
}

Test(invalid_args, get_args, .init=redirect_all_std)
{
    char *av[] = {"./server", "-p", "abcd", "-x", "-123", "-y", "-38"};
    char *av2[] = {"./server", "-E", "EEE", "-T", "ay"};
    char *av3[] = {"./server", "helloworld"};
    arg_holder_t *hldr;

    hldr = get_args(7, av);
    cr_assert(!hldr);
    hldr = get_args(5, av2);
    cr_assert(!hldr);
    hldr = get_args(2, av3);
    cr_assert(!hldr);
}

Test(invalid_args2, get_args, .init=redirect_all_std)
{
    char *av[] = {"./server", "-p", "123", "-n", "-x", "100"};
    char *av2[] = {"./server", "-y", "ABC", "-x", "100"};
    char *av3[] = {"./server", "-f", "-3"};
    arg_holder_t *hldr;

    hldr = get_args(6, av);
    cr_assert(!hldr);
    hldr = get_args(5, av2);
    cr_assert(!hldr);
    hldr = get_args(3, av3);
    cr_assert(!hldr);
}