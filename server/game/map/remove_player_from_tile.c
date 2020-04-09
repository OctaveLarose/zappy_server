/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"
#include "game/map.h"

/// \brief Remove a player from a tile
/// \param player
/// \param tile
/// \return true or false, depending on success
bool remove_player_from_tile(player_t *player, tile_t *tile)
{
    player_t *prev = NULL;
    player_t *idx = tile->players;
    player_t *next = NULL;

    if (idx != NULL && idx == player) {
        tile->players = tile->players->next_neighbor;
        return (true);
    }
    while (idx != NULL && idx != player) {
        prev = idx;
        idx = idx->next_neighbor;
        next = idx->next_neighbor;
    }
    if (idx == NULL)
        return (false);
    idx->next_neighbor = NULL;
    prev->next_neighbor = next;
    return (true);
}