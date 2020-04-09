/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"
#include "network/client.h"

game_t *get_game_tests(void);

Test(broadcast, commands)
{
    game_t *game;
    char *cmd = strdup("Broadcast hello world!");
    player_t *player;
    player_t *player2;
    client_t *client;
    client_t *client2;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};

    cr_assert(cmd);
    game = get_game_tests();
    player = make_new_player(game, info);
    client = create_client(4546);
    player2 = make_new_player(game, info);
    client2 = create_client(4546);
    cr_assert(player && player2 && client && client2);
    player->client = (client_ai_t*)client;
    player2->client = (client_ai_t*)client2;
    cr_assert_eq(cmd_broadcast(cmd, player, game), RESP_OK);
    cr_assert_str_eq(player2->client->base.buffer_out.buffer, \
"message 0, hello world!\n");
}