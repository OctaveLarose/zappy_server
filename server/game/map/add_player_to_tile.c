/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"
#include "game/map.h"

/// \brief Push a player into the tile's players linked list
/// \param tile
/// \param player
/// \return true or false, depending on success
bool append_to_tile_player_list(tile_t *tile, player_t *player)
{
    player_t *last;

    if (tile == NULL)
        return (false);
    last = get_last_tile_player(tile);
    if (last == NULL)
        tile->players = player;
    else
        last->next_neighbor = player;
    player->next_neighbor = NULL;
    return (true);
}