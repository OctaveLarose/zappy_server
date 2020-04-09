/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/team.h"

bool check_if_game_won(team_t *teams)
{
    for (int i = 0; teams[i].name != NULL; i++) {
        if (teams[i].max_lvl_players >= NBR_PLAYERS_TO_WIN) {
            printf("Team %s won!\n", teams[i].name);
            return (true);
        }
    }
    return (false);
}