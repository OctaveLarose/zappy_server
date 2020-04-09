/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "game/map.h"
#include "errors.h"
#include "macros.h"

void free_map(tile_t *map)
{
    if (map)
        free(map);
}

/// \brief Allocate the map, set its width and height and link all tiles
///        together
/// \param world
/// \param width
/// \param height
/// \return
int init_world(world_t *world, int width, int height)
{
    world->width = width;
    world->height = height;
    world->map = calloc(1, sizeof(tile_t) * (width * height));
    if (!world->map) {
        free(world);
        return (error_print("calloc failed in init_world()"));
    }
    link_tiles(world->map, world->width, world->height);
    return (OK);
}