/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/commands.h"
#include "arg_holder.h"

game_t *get_game_tests(void);

int get_nbr_players_in_game(game_t *game)
{
    int nbr = 0;

    for (player_t *tmp = game->players; tmp; tmp = tmp->next_player)
        nbr++;
    return (nbr);
}

Test(fork, commands)
{
    game_t *game;
    player_t *player;

    game = get_game_tests();
    cr_assert_eq(get_nbr_players_in_game(game), 0);
    player = make_new_player(game, (player_info_t){false, false, {0, 0}, \
NULL, NULL});
    cr_assert(player);
    cr_assert_eq(has_pending_commands(player), false);
    cr_assert_eq(get_nbr_players_in_game(game), 1);
    cr_assert_eq(cmd_fork(NULL, player, game), RESP_OK);
    cr_assert_eq(get_nbr_players_in_game(game), 2);
    cr_assert_neq(game->players, NULL);
    player = get_last_global_player(game->players);
    cr_assert_eq(player->level, EGG);
    cr_assert_eq(player->team, NULL);
    cr_assert(player->action_time_left != 0);
}