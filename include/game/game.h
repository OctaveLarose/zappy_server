/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef GAME_H_
#define GAME_H_

#include <stdio.h>
#include "team.h"
#include "map.h"

typedef struct s_arg_holder arg_holder_t;

#define GAME_WIN 42
#define RESOURCE_SPAWN_RATE 30
#define FOOD_EXTRA_SPAWN_RATE 50
#define SECOND_NBR (CLOCKS_PER_SEC / 100)
#define TIME_UNITS_PER_FOOD 126
#define MAX_FOOD_PER_TILE 40
#define MAX_RES_PER_TILE 5

typedef struct s_buffer {
    char str[MAX_CMD_LEN];
    int len;
} buffer_t;

typedef struct s_game {
    team_t *teams;
    player_t *players;
    world_t world;
    double freq;
    buffer_t game_log;
} game_t;

int init_game(game_t *game, arg_holder_t *args);

int update_game(game_t *game);

bool check_if_game_won(team_t *teams);

int strcmp_until_space(char *s1, char *s2);

bool set_player_command(player_t *player, double freq, buffer_t *game_log);

int execute_player_command(char *cmd, player_t *player, game_t *game);

bool fill_response_to_client(c_buffer_t *buffer_response, int val);

bool add_str_to_buffer(char *str, buffer_t *buffer);

void reset_buffer(buffer_t *buffer);

#endif
