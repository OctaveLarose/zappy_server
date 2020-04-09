/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"

/// \brief check if the player have commands in his buffer to be executed
/// \param player
/// \return true if commands, false if not
bool has_pending_commands(player_t *player)
{
    if (!player->client)
        return (false);
    for (int i = 0; i < MAX_COMMANDS; i++)
        if (player->client->base.commands[i][0] != '\0')
            return (true);
    return (false);
}