/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/


#include "game/commands.h"
#include "macros.h"

/// \brief Fork a player to a egg
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_fork(char *cmd, player_t *player, game_t *game)
{
    player_t *egg;
    player_info_t info;

    UNUSED(cmd);
    info.client = NULL;
    info.team = player->team;
    info.is_egg = true;
    info.random_pos = false;
    info.pos = player->tile->pos;
    egg = make_new_player(game, info);
    return (egg ? RESP_OK : RESP_KO);
}