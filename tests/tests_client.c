/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "network/client.h"

Test(basic, client)
{
    client_t *start = NULL;
    client_t *new = create_client(42);

    cr_assert(!start && !get_last_client(start));
    start = create_client(34);
    cr_assert(start && new);
    cr_assert(append_to_client_list(&start, new));
    cr_assert_eq(start->base.next, new);
    cr_assert_eq(get_last_client(start), new);
    cr_assert_eq(get_client_by_fd(start, 99), NULL);
    cr_assert_eq(get_client_by_fd(start, 42), new);
    delete_client(&start, 34);
    cr_assert_eq(start->base.socket, 42);
}

Test(delete, client)
{
    int start_fd = 100;
    client_t *start = create_client(start_fd);
    client_t *tmp;

    for (int i = start_fd + 1; i < 115; i++) {
        tmp = create_client(i);
        cr_assert(tmp);
        cr_assert(append_to_client_list(&start, tmp));
    }
    delete_client(&start, 110);
    for (int i = 114; i > start_fd; i--) {
        if (i == 110)
            continue;
        tmp = get_last_client(start);
        cr_assert(tmp && tmp->base.socket == i);
        delete_client(&start, i);
    }
    delete_client(&start, 100);
    cr_assert_eq(start, NULL);
}