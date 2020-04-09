/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Send hatch to the graphic client
/// \param player
/// \param game_log
/// \return
int hatch_log(player_t *player, buffer_t *game_log)
{
    char log_msg[25];

    sprintf(log_msg, "htc %d\n", player->id);
    return (add_str_to_buffer(log_msg, game_log));
}