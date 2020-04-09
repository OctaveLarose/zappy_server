/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/map.h"

/// \brief Remove resources from the given tile
/// \param inv
/// \param tile
/// \return
bool remove_resources_from_tile(const inventory_t *inv, tile_t *tile)
{
    inventory_t *inv_tile = &tile->inventory;
    const uint16_t *inv_arr = (uint16_t *) inv;
    bool res = true;

    for (int i = 0; i < NB_RESOURCES; i++)
        for (int j = 0; j < inv_arr[i]; j++)
            res = del_resource_from_inventory(inv_tile, i);
    return (res);
}