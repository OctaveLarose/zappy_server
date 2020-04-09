/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef ZAPPY_H_
#define ZAPPY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <limits.h>

#include "macros.h"
#include "tools.h"
#include "errors.h"
#include "arg_holder.h"
#include "network/server.h"
#include "game/game.h"

#define ZAPPY_NO_TIMEOUT false
#define ZAPPY_RESET_AFTER_OVER false
#define ZAPPY_END_GAME_WHEN_PLAYERS_DEAD false

typedef struct s_zappy {
    server_t server;
    game_t game;
} zappy_t;

int init_zappy(zappy_t *zappy, arg_holder_t *args);

void free_zappy(zappy_t *zappy);

int run_zappy(zappy_t *zappy);

void clock_tick(zappy_t *zappy, clock_t time_start);

void check_for_timeouts(zappy_t *zappy);

#endif
