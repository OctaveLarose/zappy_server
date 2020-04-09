/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/inventory.h"

/// \brief Add the resource in the given inventory
/// \param inventory
/// \param resource
/// \return
bool add_resource_to_inventory(inventory_t *inventory, resource_t resource)
{
    uint16_t *inv_arr;

    if (!inventory)
        return (false);
    inv_arr = (uint16_t *) inventory;
    if (*(inv_arr + resource) + 1 >= INT16_MAX)
        return (false);
    *(inv_arr + resource) += 1;
    return (true);
}

/// \brief Relive the resource from the given inventory
/// \param inventory
/// \param resource
/// \return true if success, false otherwise
bool del_resource_from_inventory(inventory_t *inventory, resource_t resource)
{
    uint16_t *inv_arr;

    if (!inventory)
        return (false);
    inv_arr = (uint16_t *) inventory;
    if (*(inv_arr + resource) <= 0)
        return (false);
    *(inv_arr + resource) -= 1;
    return (true);
}

/// \brief Move a resource between to inventories
/// \param inv_from
/// \param inv_to
/// \param res
/// \return true if success, false otherwise
bool transfer_item(inventory_t *inv_from, inventory_t *inv_to, resource_t res)
{
    if (!del_resource_from_inventory(inv_from, res))
        return (false);
    return (add_resource_to_inventory(inv_to, res));
}