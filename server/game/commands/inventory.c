/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "macros.h"
#include "game/commands.h"

/// \brief send the player's inventory
/// \param cmd
/// \param player
/// \param game
/// \return status
int cmd_inventory(char *cmd, player_t *player, game_t *game)
{
    char buf_response[130];
    inventory_t inv = player->inventory;

    UNUSED(cmd);
    UNUSED(game);
    sprintf(buf_response, INVENTORY_STRING, inv.food, inv.linemate, \
inv.deraumere, inv.sibur, inv.mendiane, inv.phiras, \
inv.thystame);
    add_to_buffer(buf_response, &player->client->base.buffer_out);
    return (RESP_OTHER);
}