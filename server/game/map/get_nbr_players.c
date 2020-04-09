/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"
#include "game/map.h"

/// \brief Count players with a given level
/// \param tile
/// \param lvl
/// \return count
int get_nbr_players_of_lvl_on_tile(tile_t *tile, int lvl)
{
    int nbr = 0;

    for (player_t *tmp = tile->players; tmp; tmp = tmp->next_neighbor)
        if (tmp->level == lvl)
            nbr++;
    return (nbr);
}

/// \brief Count players
/// \param tile
/// \return count
int get_nbr_players_on_tile(tile_t *tile)
{
    int nbr = 0;

    for (player_t *tmp = tile->players; tmp; tmp = tmp->next_neighbor)
        nbr++;
    return (nbr);
}