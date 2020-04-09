/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "game/log.h"
#include "game/player.h"
#include "macros.h"

Test(forward_log, log)
{
    buffer_t game_log;
    world_t world;
    player_t *player;
    player_info_t info = (player_info_t){false, false, \
(vec2i_t){1, 1}, NULL, NULL};
    char buf[30];

    cr_assert_eq(init_world(&world, 10, 10), OK);
    game_log.len = 0;
    player = create_player(info, &world, 2);
    cr_assert(player);
    sprintf(buf, "mov %d %d\n", player->id, player->direction);
    forward_log(player, &game_log);
    cr_assert_str_eq(buf, game_log.str);
    free_player(player);
}

Test(take_log, log)
{
    buffer_t game_log;

    game_log.len = 0;
    take_log(42, 2, &game_log);
    cr_assert_str_eq(game_log.str, "tak 42 2\n");
    take_log(2, 5, &game_log);
    take_log(87, 1, &game_log);
    cr_assert_str_eq(game_log.str, "tak 42 2\ntak 2 5\ntak 87 1\n");
}

Test(spawn_player, log)
{
    buffer_t game_log;
    world_t world;
    player_t *player;
    player_info_t info = (player_info_t){false, false, \
(vec2i_t){4, 7}, NULL, NULL};
    char buf[100];

    cr_assert_eq(init_world(&world, 10, 10), OK);
    game_log.len = 0;
    player = create_player(info, &world, 2);
    cr_assert(player);
    cr_assert(spawn_player_log(player, &game_log));
    sprintf(buf, "spw 4 7 P 0 %d NO_TEAM\n", player->direction);
    cr_assert_str_eq(game_log.str, buf);
    free_player(player);
}

Test(spawn_resource, log)
{
    buffer_t game_log;
    vec2i_t pos = (vec2i_t){34, 45};

    game_log.len = 0;
    spawn_resource_log(&pos, 3, &game_log);
    cr_assert_str_eq(game_log.str, "spw 34 45 3\n");
    pos = (vec2i_t){0, 0};
    spawn_resource_log(&pos, 1, &game_log);
    pos = (vec2i_t){4, 19};
    spawn_resource_log(&pos, 5, &game_log);
    cr_assert_str_eq(game_log.str, "spw 34 45 3\nspw 0 0 1\nspw 4 19 5\n");
}

Test(incantation, log)
{
    buffer_t game_log;
    vec2i_t pos = (vec2i_t){34, 45};

    game_log.len = 0;
    incantation_start_log(&pos, &game_log);
    cr_assert_str_eq(game_log.str, "inc 34 45\n");
    pos = (vec2i_t){0, 0};
    incantation_end_log(&pos, true, &game_log);
    pos = (vec2i_t){4, 19};
    incantation_end_log(&pos, false, &game_log);
    cr_assert_str_eq(game_log.str, "inc 34 45\nend 0 0 OK\nend 4 19 KO\n");
}