/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Send a notification to the graphic that a player moved forward
/// \param player
/// \param game_log
/// \return
int forward_log(player_t *player, buffer_t *game_log)
{
    char log_msg[30];

    sprintf(log_msg, "mov %d %d\n", player->id, player->direction);
    return (add_str_to_buffer(log_msg, game_log));
}

int dir_log(player_t *player, buffer_t *game_log)
{
    char log_msg[40];

    sprintf(log_msg, "dir %d %d\n", player->id, player->direction);
    return (add_str_to_buffer(log_msg, game_log));
}