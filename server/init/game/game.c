/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "macros.h"
#include "game/game.h"
#include "arg_holder.h"

/// \brief Initialize the game (world, team, set the frequency)
/// \param game
/// \param args
/// \return
int init_game(game_t *game, arg_holder_t *args)
{
    if (init_world(&game->world, args->width, args->height))
        return (ERR);
    game->teams = init_teams(args->names, args->clients_nbr);
    game->freq = args->freq;
    if (!game->teams)
        return (ERR);
    game->players = NULL;
    memset(game->game_log.str, 0, MAX_CMD_LEN);
    game->game_log.len = 0;
    return (OK);
}