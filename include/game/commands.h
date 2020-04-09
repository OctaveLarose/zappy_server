/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include "game.h"

typedef int (*cmd_ptr_t)(char *, player_t *, game_t *);

#define RESP_OK 0
#define RESP_KO 84
#define RESP_OTHER 42

#define INCANTATION_CMD_IDX 11
#define INVENTORY_STRING "[ food %d, linemate %d, deraumere %d, sibur %d, \
mendiane %d, phiras %d, thystame %d ]\n"
#define ELEVATION_UNDERWAY_MSG "Elevation underway\n"

struct s_command {
    char *name;
    cmd_ptr_t cmd_ptr;
    double time_limit;
};

extern const struct s_command command_list[];

typedef struct s_ritual_data {
    int level;
    int nb_players;
    inventory_t inv;
} ritual_data_t;

extern const struct s_ritual_data ritual_data[];

int cmd_forward(char *, player_t *, game_t *);

int cmd_left(char *, player_t *, game_t *);

int cmd_right(char *, player_t *, game_t *);

int cmd_look(char *, player_t *, game_t *);
int look_tile(buffer_t *buffer, tile_t *tile);

int cmd_inventory(char *, player_t *, game_t *);

int cmd_broadcast(char *, player_t *, game_t *);

int cmd_connect_nbr(char *, player_t *, game_t *);

int cmd_fork(char *, player_t *, game_t *);

int cmd_eject(char *, player_t *, game_t *);

int cmd_take(char *, player_t *, game_t *);

int cmd_set(char *, player_t *, game_t *);

int cmd_incantation(char *, player_t *, game_t *);

bool check_if_ritual_req_met(const ritual_data_t *, player_t *);

#endif