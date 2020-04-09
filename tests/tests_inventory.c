/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/inventory.h"

Test(get_random_resource, inventory)
{
    resource_t random_res;

    for (int i = 0; i < 500; i++) {
        random_res = get_random_resource();
        cr_assert(0 <= random_res && random_res <= 6);
    }
}

Test(get_random_from_str, inventory)
{
    char *arr[] = {"food", "linemate", "deraumere", "sibur", "mendiane", \
"phiras", "thystame", "abcd", "err"};

    for (int i = 0; i < NB_RESOURCES; i++)
        cr_assert_eq(get_resource_from_str(arr[i]), i);
    cr_assert_eq(get_resource_from_str(arr[NB_RESOURCES]), INVALID_RES);
    cr_assert_eq(get_resource_from_str(arr[NB_RESOURCES + 1]), INVALID_RES);
}

Test(transfer_item, inventory)
{
    inventory_t inv_from;
    inventory_t inv_to;

    memset(&inv_from, 0, sizeof(inventory_t));
    memset(&inv_to, 0, sizeof(inventory_t));
    cr_assert(!transfer_item(&inv_from, &inv_to, LINEMATE));
    cr_assert(add_resource_to_inventory(&inv_from, LINEMATE));
    cr_assert(transfer_item(&inv_from, &inv_to, LINEMATE));
}