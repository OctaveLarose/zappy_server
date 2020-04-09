/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"
#include "arg_holder.h"

game_t *get_game_tests(void)
{
    game_t *game = malloc(sizeof(game_t));
    int ac = 12;
    char *av[] = {"./server", "-p", "123", "-x", "10", "-y", "20", \
"-n", "name1", "name2", "-c", "34"};
    arg_holder_t *hldr;

    cr_assert(game);
    hldr = get_args(ac, av);
    cr_assert(hldr);
    init_game(game, hldr);
    return (game);
}

Test(forward, commands)
{
    game_t *game;
    player_t *player;
    player_info_t info = (player_info_t){false, true, {0, 0}, NULL, NULL};
    vec2i_t pos;
    vec2i_t *tile_pos;

    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    pos = player->tile->pos;
    cr_assert_eq(cmd_forward(NULL, player, game), RESP_OK);
    tile_pos = &player->tile->pos;
    cr_assert((pos.x != tile_pos->x) || (pos.y != tile_pos->y));
}

Test(left, commands)
{
    game_t *game;
    player_t *player;
    player_info_t info = (player_info_t){false, true, {0, 0}, NULL, NULL};
    dir_t dir;

    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    for (int i = 0; i < 10; i++) {
        dir = player->direction;
        cr_assert_eq(cmd_left(NULL, player, game), RESP_OK);
        cr_assert_eq(player->direction, get_dir_to_left(dir));
    }
    player->direction = INVALID_DIR;
    cr_assert_eq(cmd_left(NULL, player, game), RESP_KO);
}

Test(right, commands)
{
    game_t *game;
    player_t *player;
    player_info_t info = (player_info_t){false, true, {0, 0}, NULL, NULL};
    dir_t dir;

    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    for (int i = 0; i < 10; i++) {
        dir = player->direction;
        cr_assert_eq(cmd_right(NULL, player, game), RESP_OK);
        cr_assert_eq(player->direction, get_dir_to_right(dir));
    }
    player->direction = INVALID_DIR;
    cr_assert_eq(cmd_right(NULL, player, game), RESP_KO);
}