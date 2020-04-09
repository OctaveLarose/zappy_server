/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include "game/map.h"
#include "macros.h"

Test(add_resource_to_inventory, spawn_food)
{
    inventory_t inventory;
    resource_t resource;

    memset(&inventory, 0, sizeof(inventory_t));
    cr_assert_eq(inventory.linemate, 0);
    for (int i = 1; i < NB_RESOURCES + 1; i++) {
        resource = i - 1;
        for (int j = 0; j < i; j++)
            add_resource_to_inventory(&inventory, resource);
    }
    cr_assert_eq(inventory.food, 1);
    cr_assert_eq(inventory.linemate, 2);
    cr_assert_eq(inventory.deraumere, 3);
    cr_assert_eq(inventory.sibur, 4);
    cr_assert_eq(inventory.mendiane, 5);
    cr_assert_eq(inventory.phiras, 6);
    cr_assert_eq(inventory.thystame, 7);
}

Test(spawn_food, spawn_food)
{
    world_t world;
    vec2i_t pos;
    resource_t resource;
    tile_t *cur_tile;
    uint16_t last_resource_val;

    cr_assert(init_world(&world, 100, 100) != ERR);
    for (int i = 0; i < 30; i++) {
        srand(clock());
        resource = get_random_resource();
        init_random_pos(&pos, world.width, world.height);
        cur_tile = get_tile(&world, &pos);
        cr_assert(cur_tile);
        last_resource_val = *((uint16_t*) &cur_tile->inventory + resource);
        spawn_resource_at_pos(&world, &pos, resource);
        cr_assert(*((uint16_t*) &cur_tile->inventory + resource) == \
        last_resource_val + 1);
    }
}