/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose.
*/

#include "game/map.h"
#include "macros.h"

/// \brief Link a tile with his neighbours
/// \param i
/// \param init_tile
/// \param width
/// \param height
void link_tile(int i, tile_t *init_tile, int width, int height)
{
    tile_t *tile = init_tile + i;

    if (i % width != 0 && i != 0)
        tile->left = tile - 1;
    else
        tile->left = tile + (width - 1);
    if ((i + 1) % width != 0 || (i == 0 && width > 1))
        tile->right = tile + 1;
    else
        tile->right = tile - (width - 1);
    if (i >= width)
        tile->up = tile - width;
    else
        tile->up = tile + width * (height - 1);
    if (i < width * (height - 1) && width > 1)
        tile->down = tile + width;
    else
        tile->down = init_tile + i % width;
}

/// \brief Link all tiles with each other, to make the map circular
/// \param map
/// \param width
/// \param height
void link_tiles(tile_t *map, int width, int height)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < width * height; i++) {
        (map + i)->pos.x = x;
        (map + i)->pos.y = y;
        link_tile(i, map, width, height);
        x++;
        if (x >= width) {
            y++;
            x = 0;
        }
    }
}