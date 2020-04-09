/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"

game_t *get_game_tests(void);

Test(eject_alone, commands)
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
    cr_assert_eq(cmd_eject(NULL, player, game), RESP_OK);
    cr_assert_str_eq(client->base.buffer_out.buffer, "");
}

Test(eject_with_pals, commands)
{
    game_t *game;
    player_t *player;
    player_t *player2;
    client_t *client;
    client_t *client2;
    vec2i_t pos = {3, 3};
    player_info_t info = (player_info_t){false, false, pos, NULL, NULL};
    char *dir_str;
    char buf[40];

    game = get_game_tests();
    player = make_new_player(game, info);
    player2 = make_new_player(game, info);
    client = create_client(4546);
    client2 = create_client(4547);
    cr_assert(player && client && player2 && client2);
    player->client = (client_ai_t*)client;
    player2->client = (client_ai_t*)client2;
    dir_str = dir_to_str(player->direction);
    cr_assert_neq(dir_str, NULL);
    cr_assert_eq(cmd_eject(NULL, player, game), RESP_OK);
    cr_assert_str_eq(client->base.buffer_out.buffer, "");
    sprintf(buf, "eject : %s\n", dir_str);
    cr_assert_str_eq(client2->base.buffer_out.buffer, buf);
}