/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/inventory.h"

/// \brief Check if the player have the necessary items for a ritual
/// \param tile_inv
/// \param ritual_req
/// \return
bool check_ritual_resources(const inventory_t *tile_inv, \
const inventory_t *ritual_req)
{
    uint16_t *tile_inv_arr = (uint16_t *) tile_inv;
    uint16_t *req_inv_arr = (uint16_t *) ritual_req;

    for (int i = 0; i < NB_RESOURCES; i++)
        if (tile_inv_arr[i] < req_inv_arr[i])
            return (false);
    return (true);
}