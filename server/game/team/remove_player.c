/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/team.h"

/// \brief Remove the player from the given team linked list
/// \param player
/// \param team
/// \return true if removed, false if not
bool remove_player_from_team(player_t *player, team_t *team)
{
    player_t *prev = NULL;
    player_t *idx = team->players;
    player_t *next = NULL;

    if (idx != NULL && idx == player) {
        team->players = team->players->next_teammate;
        return (true);
    }
    while (idx != NULL && idx != player) {
        prev = idx;
        idx = idx->next_teammate;
        next = idx->next_teammate;
    }
    if (idx == NULL)
        return (false);
    idx->next_teammate = NULL;
    prev->next_teammate = next;
    return (true);
}