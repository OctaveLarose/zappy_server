/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef TEAM_H_
#define TEAM_H_

#include <string.h>
#include <stdbool.h>
#include "player.h"

#define NBR_PLAYERS_TO_WIN 6

typedef struct s_player player_t;

typedef struct s_team {
    char *name;
    int clients_num;
    int max_lvl_players;
    player_t *players;
} team_t;

team_t *init_teams(char **team_names, int nb_max_clients);
team_t init_team(char *name, int nb_clients_max);
void print_teams(team_t *teams);
void free_team_array(team_t *teams);
team_t *get_team(team_t *teams, char *team_name);
int get_team_nbr_players(team_t *team);
int get_team_nbr_players_free(team_t *team);
int get_team_nbr_players_not_free(team_t *team);

bool append_to_team_player_list(team_t *team, player_t *player);
player_t *get_last_team_player(team_t *team);
bool remove_player_from_team(player_t *player, team_t *team);

#endif