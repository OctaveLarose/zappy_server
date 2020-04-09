/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"
#include "network/client.h"
#include "arg_holder.h"

game_t *get_game_tests(void);

Test(take, commands)
{
    game_t *game;
    char *cmd = strdup("Take linemate");
    player_t *player;
    tile_t *tile;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    cr_assert(cmd);
    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    cr_assert_eq(cmd_take(cmd, player, game), RESP_KO);
    tile = get_tile(&game->world, &pos);
    tile->inventory.linemate += 1;
    cmd = strdup("Take linemate");
    cr_assert(cmd);
    cr_assert_eq(cmd_take(cmd, player, game), RESP_OK);
    cr_assert_eq(tile->inventory.linemate, 0);
    cr_assert_eq(player->inventory.linemate, 1);
}

Test(set, commands)
{
    game_t *game;
    char *cmd = strdup("Set linemate");
    player_t *player;
    tile_t *tile;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    cr_assert(cmd);
    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    cr_assert_eq(cmd_set(cmd, player, game), RESP_KO);
    player->inventory.linemate += 1;
    tile = get_tile(&game->world, &pos);
    cmd = strdup("Set linemate");
    cr_assert(cmd);
    cr_assert_eq(cmd_set(cmd, player, game), RESP_OK);
    cr_assert_eq(tile->inventory.linemate, 1);
    cr_assert_eq(player->inventory.linemate, 0);
}

Test(take_no_arg, commands)
{
    game_t *game;
    char *cmd = strdup("Take");
    player_t *player;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    cr_assert(cmd);
    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    cr_assert_eq(cmd_take(cmd, player, game), RESP_KO);
}

Test(set_no_arg, commands)
{
    game_t *game;
    char *cmd = strdup("Set");
    player_t *player;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    cr_assert(cmd);
    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    cr_assert_eq(cmd_take(cmd, player, game), RESP_KO);
}