/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#ifndef LOG_H_
#define LOG_H_

#include "game/game.h"

int forward_log(player_t *player, buffer_t *game_log);
int dir_log(player_t *player, buffer_t *game_log);
bool spawn_player_log(player_t *player, buffer_t *game_log);
bool spawn_resource_log(vec2i_t *pos, resource_t resource, buffer_t *game_log);
int take_log(int player_id, resource_t res, buffer_t *game_log);
int take_log_inventory(const inventory_t *, int , buffer_t *);
int incantation_start_log(vec2i_t *pos, buffer_t *game_log);
int incantation_end_log(vec2i_t *pos, bool res, buffer_t *game_log);
int hatch_log(player_t *player, buffer_t *game_log);
int kill_log(player_t *player, buffer_t *game_log);

#endif