/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef MAP_H_
#define MAP_H_

#include <stdbool.h>
#include <time.h>

#include "game/inventory.h"

typedef struct s_player player_t;
typedef struct s_buffer buffer_t;
typedef enum dir dir_t;

#define DIR_STR "NORTH", "EAST", "SOUTH", "WEST"
typedef enum dir {
    INVALID_DIR = -1,
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3
} dir_t;

typedef struct s_vec2i {
    int x;
    int y;
} vec2i_t;

typedef struct s_vec2d {
    double x;
    double y;
} vec2d_t;

typedef struct s_tile {
    struct s_tile *up;
    struct s_tile *down;
    struct s_tile *left;
    struct s_tile *right;
    inventory_t inventory;
    vec2i_t pos;
    player_t *players;
} tile_t;

typedef struct s_world {
    unsigned int width;
    unsigned int height;
    tile_t *map;
} world_t;

void free_map(tile_t *map);

int init_world(world_t *world, int width, int height);

tile_t *init_map(int width, int height);

void link_tiles(tile_t *map, int width, int height);

tile_t *get_tile(world_t *map, vec2i_t *pos);

tile_t *get_random_tile(world_t *world);

tile_t *get_tile_in_dir(tile_t *tile, dir_t dir);

void init_random_pos(vec2i_t *pos, int width, int height);

void spawn_resource(world_t *world, buffer_t *game_log);

bool spawn_resource_at_pos(world_t *map, vec2i_t *pos, resource_t resource);

bool move_player_to_tile(player_t *player, tile_t *tile);

bool move_player_in_dir(player_t *player, dir_t dir);

char *dir_to_str(dir_t);

dir_t get_dir_to_left(dir_t dir);

dir_t get_dir_to_right(dir_t dir);

int get_nbr_players_on_tile(tile_t *tile);

int get_nbr_players_of_lvl_on_tile(tile_t *tile, int lvl);

bool append_to_tile_player_list(tile_t *tile, player_t *player);

player_t *get_last_tile_player(tile_t *tile);

bool remove_player_from_tile(player_t *player, tile_t *tile);

bool remove_resources_from_tile(const inventory_t *inv, tile_t *tile);

#endif