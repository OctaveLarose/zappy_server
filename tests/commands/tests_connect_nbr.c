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
#include "game/team.h"

game_t *get_game_tests(void);

Test(connect_nbr, commands)
{
    game_t *game;
    player_t *player;
    team_t team;
    client_t *client;

    game = get_game_tests();
    client = create_client(1132);
    cr_assert(client);
    team = init_team("abc", 123);
    player = make_new_player(game, (player_info_t){false, false, {3, 3}, \
NULL, (client_ai_t*)client});
    cr_assert(player);
    cr_assert_eq(cmd_connect_nbr(NULL, player, game), RESP_KO);
    player->team = &team;
    cr_assert_eq(cmd_connect_nbr(NULL, player, game), RESP_OTHER);
        cr_assert_str_eq(client->base.buffer_out.buffer, "123\n");
}