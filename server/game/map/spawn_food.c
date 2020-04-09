/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <stdio.h>
#include "game/log.h"
#include "game/game.h"

/// \brief Spawn a resource at the given pos in the world
/// \param map
/// \param pos
/// \param resource
bool spawn_resource_at_pos(world_t *map, vec2i_t *pos, resource_t resource)
{
    tile_t *tile = get_tile(map, pos);
    uint16_t *inv_arr;

    if (!tile)
        return (false);
    inv_arr = (uint16_t*)&tile->inventory;
    if (resource == FOOD && tile->inventory.food >= MAX_FOOD_PER_TILE)
        return (false);
    else if (inv_arr[resource] >= MAX_RES_PER_TILE)
        return (false);
    return (add_resource_to_inventory(&tile->inventory, resource));
}

/// \brief Fill a vector with random value, boundaries are width and height
/// \param pos
/// \param width
/// \param height
void init_random_pos(vec2i_t *pos, int width, int height)
{
    pos->x = rand() % width;
    pos->y = rand() % height;
}

/// \brief Add a resource in the given world, and a spawn msg in the game_log
/// \param world
/// \param game_log
void spawn_resource(world_t *world, buffer_t *game_log)
{
    vec2i_t pos;
    resource_t resource;

    srand(clock());
    resource = get_random_resource();
    init_random_pos(&pos, world->width, world->height);
    if (spawn_resource_at_pos(world, &pos, resource))
        spawn_resource_log(&pos, resource, game_log);
}