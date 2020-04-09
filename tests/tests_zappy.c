/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "zappy.h"

Test(zappy_normal, zappy)
{
    arg_holder_t *args;
    char *arg_arr[] = {"./zappy", "-p", "4242", "-x", "60", "-y", "10", "-n", \
"name1", "name2", "name3", "a", "-c", "12"};
    zappy_t zappy;

    args = get_args(14, arg_arr);
    cr_assert(args);
    init_zappy(&zappy, args);
    cr_assert_eq(zappy.game.world.width, 60);
    cr_assert_eq(zappy.game.world.height, 10);
    cr_assert_neq(zappy.game.world.map, NULL);
    cr_assert_str_eq(zappy.game.teams[0].name, "name1");
    cr_assert_str_eq(zappy.game.teams[1].name, "name2");
    cr_assert_str_eq(zappy.game.teams[2].name, "name3");
    cr_assert_str_eq(zappy.game.teams[3].name, "a");
    cr_assert_eq(zappy.game.teams[4].name, NULL);
    cr_assert_eq(zappy.game.teams[0].clients_num, 12);
    cr_assert_eq(zappy.server.port, 4242);
}