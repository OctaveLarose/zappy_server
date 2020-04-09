/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"

game_t *get_game_tests(void);

Test(incantation_req_met, commands)
{
    game_t *game;
    player_t *player;
    client_t *client;
    vec2i_t pos = {3, 3};
    tile_t *tile;
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    game = get_game_tests();
    player = make_new_player(game, info);
    client = create_client(4546);
    cr_assert(player && client);
    player->client = (client_ai_t*)client;
    tile = get_tile(&game->world, &pos);
    cr_assert(tile);
    tile->inventory.linemate++;
    cr_assert_eq(tile->inventory.linemate, 1);
    cr_assert_eq(cmd_incantation(NULL, player, game), RESP_OTHER);
    cr_assert_str_eq(client->base.buffer_out.buffer, "Current level: 2\n");
    cr_assert_eq(tile->inventory.linemate, 0);
}

Test(incantation_req_not_met, commands)
{
    game_t *game;
    player_t *player;
    client_t *client;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    game = get_game_tests();
    player = make_new_player(game, info);
    client = create_client(4546);
    cr_assert(player && client);
    player->client = (client_ai_t*)client;
    cr_assert_eq(cmd_incantation(NULL, player, game), RESP_OTHER);
    cr_assert_str_eq(client->base.buffer_out.buffer, "ko\n");
}

Test(incantation_invalid_level, commands)
{
    game_t *game;
    player_t *player;
    client_t *client;
    tile_t *tile;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    game = get_game_tests();
    player = make_new_player(game, info);
    client = create_client(4546);
    cr_assert(player && client);
    player->client = (client_ai_t*)client;
    tile = get_tile(&game->world, &pos);
    cr_assert(tile);
    tile->inventory.linemate++;
    player->level = 100;
    cr_assert_eq(cmd_incantation(NULL, player, game), RESP_OTHER);
    cr_assert_str_eq(client->base.buffer_out.buffer, "ko\n");
}