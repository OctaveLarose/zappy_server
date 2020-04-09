/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"
#include "game/map.h"

/// \brief Get the last player in the linked list of players of a tile
/// \param tile
/// \return The player, or null if tile is empty
player_t *get_last_tile_player(tile_t *tile)
{
    player_t *first = tile->players;

    if (first == NULL)
        return (NULL);
    while (first->next_neighbor != NULL)
        first = first->next_neighbor;
    return (first);
}