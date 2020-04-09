/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <stdio.h>
#include "game/team.h"

/// \brief Get a team from a team name in the team linked list
/// \param teams
/// \param team_name
/// \return the found team, NULL otherwise
team_t *get_team(team_t *teams, char *team_name)
{
    for (int i = 0; teams[i].name != NULL; i++) {
        if (strcmp(teams[i].name, team_name) == 0)
            return (&teams[i]);
    }
    dprintf(2, "Wrong team name : '%s'.\n", team_name);
    return (NULL);
}