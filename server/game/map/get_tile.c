/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/map.h"

/// \brief Get the tile at the given position in the world
/// \param world
/// \param pos
/// \return a pointer to the tile or null if not found
tile_t *get_tile(world_t *world, vec2i_t *pos)
{
    tile_t *tile = world->map;

    if (pos->x > (int)world->width || pos->y > (int)world->height)
        return (NULL);
    tile += (pos->x + world->width * pos->y);
    return (tile);
}

/// \brief Get the next tile in the given direction
/// \param tile
/// \param dir
/// \return the found tile, or null if invalid direction
tile_t *get_tile_in_dir(tile_t *tile, dir_t dir)
{
    switch (dir) {
    case NORTH:
        return (tile->up);
    case EAST:
        return (tile->right);
    case SOUTH:
        return (tile->down);
    case WEST:
        return (tile->left);
    default:
        return (NULL);
    }
}

/// \brief Pick a random tile in the world
/// \param world
/// \return a pointer to the tile
tile_t *get_random_tile(world_t *world)
{
    vec2i_t pos;

    init_random_pos(&pos, world->width, world->height);
    return (get_tile(world, &pos));
}