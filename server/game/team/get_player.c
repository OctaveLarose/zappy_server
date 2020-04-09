/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/team.h"

/// \brief Get the last player in a given team
/// \param team
/// \return a pointer to the player
player_t *get_last_team_player(team_t *team)
{
    player_t *first = team->players;

    if (first == NULL)
        return (NULL);
    while (first->next_teammate != NULL)
        first = first->next_teammate;
    return (first);
}