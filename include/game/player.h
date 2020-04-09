/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include <time.h>
#include "team.h"
#include "inventory.h"
#include "map.h"
#include "network/client.h"

typedef struct s_game game_t;
typedef struct s_tile tile_t;
typedef struct s_client_ai client_ai_t;
typedef struct s_team team_t;
typedef struct s_world world_t;
typedef struct s_vec2i vec2i_t;

#define EGG 0
#define START_FOOD 10
#define MAX_LEVEL 8

typedef struct s_player_info {
    bool is_egg;
    bool random_pos;
    vec2i_t pos;
    team_t *team;
    client_ai_t *client;
} player_info_t;

typedef struct s_player {
    int id;
    char level;
    inventory_t inventory;
    dir_t direction;
    clock_t action_time_left;
    char *cur_action;
    clock_t ttl;
    bool in_incantation;
    client_ai_t *client;
    team_t *team;
    struct s_player *next_teammate;
    tile_t *tile;
    struct s_player *next_neighbor;
    struct s_player *next_player;
} player_t;

player_t *create_player(player_info_t info, world_t *world, double f);
player_t *make_new_player(game_t *, player_info_t info);
void free_player(player_t *player);
void free_all_players(player_t *player);
void remove_player(player_t **player, player_t **global_list);
void delete_player(player_t **player, player_t **global_list);
bool has_pending_commands(player_t *player);

bool append_to_global_player_list(player_t **first, player_t *player);
player_t *get_last_global_player(player_t *first);
unsigned int get_nbr_players_global(player_t *first);

#endif
