/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"

/// \brief Get the last player in the given's player team
/// \param first
/// \return a pointer to the last team player
player_t *get_last_global_player(player_t *first)
{
    if (first == NULL)
        return (NULL);
    while (first->next_player != NULL)
        first = first->next_player;
    return (first);
}

/// \brief Count how much players are ready
/// \param first
/// \return the count
unsigned int get_nbr_players_global(player_t *first)
{
    unsigned int nbr = 0;
    player_t *tmp = first;

    while (tmp) {
        if (tmp->client && tmp->client->base.status == READY)
            nbr++;
        tmp = tmp->next_player;
    }
    return (nbr);
}