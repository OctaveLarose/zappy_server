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

Test(look, commands)
{
    game_t *game;
    player_t *player;
    client_t *client;
    player_info_t info = (player_info_t){false, false, {3, 3}, NULL, NULL};

    game = get_game_tests();
    player = make_new_player(game, info);
    cr_assert(player);
    cr_assert_eq(cmd_look(NULL, player, game), RESP_KO);
    client = create_client(1132);
    cr_assert(client);
    player->client = (client_ai_t*)client;
    cr_assert_eq(cmd_look(NULL, player, game), RESP_OTHER);
    cr_assert_str_eq(client->base.buffer_out.buffer, "[ player,,, ]\n");
}