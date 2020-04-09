/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Send a notification to the graphic that a player died
/// \param player
/// \param game_log
/// \return
int kill_log(player_t *player, buffer_t *game_log)
{
    char log_msg[25];

    sprintf(log_msg, "kil %d\n", player->id);
    return (add_str_to_buffer(log_msg, game_log));
}