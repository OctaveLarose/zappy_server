/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/team.h"

/// \brief Count the number of players in a given team
/// \param team
/// \return count
int get_team_nbr_players(team_t *team)
{
    int nbr = 0;

    if (!team)
        return (-1);
    for (player_t *tmp = team->players; tmp; tmp = tmp->next_teammate)
        nbr++;
    return (nbr);
}

/// \brief Count how much players free from a client in a given team
/// \param team
/// \return count
int get_team_nbr_players_free(team_t *team)
{
    int nbr = 0;

    if (!team)
        return (-1);
    for (player_t *tmp = team->players; tmp; tmp = tmp->next_teammate) {
        if (!tmp->client)
            nbr++;
    }
    return (nbr);
}

/// \brief Count how much players with client in a given team
/// \param team
/// \return count
int get_team_nbr_players_not_free(team_t *team)
{
    int nbr = 0;

    if (!team)
        return (-1);
    for (player_t *tmp = team->players; tmp; tmp = tmp->next_teammate) {
        if (tmp->client)
            nbr++;
    }
    return (nbr);
}