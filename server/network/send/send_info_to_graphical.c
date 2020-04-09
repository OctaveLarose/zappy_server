/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/server.h"

/// \brief Send commands contained in the game log to the graphic client
/// \param client
/// \param game_log
/// \return true if sent, false otherwise
bool send_info_to_graphical(client_graphic_t *client, char *game_log)
{
    int len = MAX_CMD_LEN - 1;

    for (; game_log[len] != '\n' && len > 0; len--);
    if (len != MAX_CMD_LEN)
        len++;
    if (send(client->base.socket, game_log, len, 0) == -1)
        return (false);
    return (true);
}