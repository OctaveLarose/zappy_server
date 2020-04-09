/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by bgenestal,
*/

#include "zappy.h"
#include "game/team.h"

/// \brief Fill a team struct with the given name and max client
/// \param name
/// \param nb_clients_max
/// \return
team_t init_team(char *name, int nb_clients_max)
{
    team_t team = {};

    if (name)
        team.name = strdup(name);
    else
        team.name = NULL;
    team.clients_num = nb_clients_max;
    team.max_lvl_players = 0;
    team.players = NULL;
    return (team);
}

/// \brief Free the memory allocated by teams
/// \param teams
void free_team_array(team_t *teams)
{
    for (int i = 0; teams[i].name; i++)
        free(teams[i].name);
    free(teams);
}

/// \brief Allocate the memory required for teams and initialize them
/// \param team_names
/// \param nb_max_clients
/// \return
team_t *init_teams(char **team_names, int nb_max_clients)
{
    unsigned int nb_teams = get_array_size(team_names);
    team_t *ret = malloc(sizeof(team_t) * (nb_teams + 1));

    if (!ret)
        return (error_print_ptr("malloc failed in init_teams()"));
    for (unsigned int i = 0; i < nb_teams; i++)
        ret[i] = init_team(team_names[i], nb_max_clients);
    ret[nb_teams] = init_team(NULL, 0);
    return (ret);
}

void print_teams(team_t *teams)
{
    if (!teams)
        return;
    for (int i = 0; teams[i].name; i++)
        printf("team %d : %s\n", i, teams[i].name);
}