/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/team.h"

/// \brief Add a player in a team
/// \param team
/// \param player
/// \return true if successfully added, false otherwise
bool append_to_team_player_list(team_t *team, player_t *player)
{
    player_t *last;

    if (team == NULL)
        return (false);
    last = get_last_team_player(team);
    if (last == NULL)
        team->players = player;
    else
        last->next_teammate = player;
    player->next_teammate = NULL;
    return (true);
}