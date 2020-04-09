/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "macros.h"
#include "game/map.h"

Test(basic, world)
{
    world_t world;

    cr_assert(init_world(&world, 20, 30) == OK);
    cr_assert_eq(world.width, 20);
    cr_assert_eq(world.height, 30);
    cr_assert(world.map);
    free_map(world.map);
}

Test(check_map, world)
{
    world_t world;
    tile_t *map;

    cr_assert(init_world(&world, 5, 4) == OK);
    map = world.map;
    cr_assert_eq(map, map->right->right->right->right->right);
    cr_assert_eq(map, map->left->left->left->left->left);
    cr_assert_eq(map->down->down, map->up->up);
    cr_assert_eq(map->up->up->up->left, map->right->down->right->right->right);
    free_map(world.map);
}

Test(go_through_map, world)
{
    world_t world;
    tile_t *map;
    tile_t *tile;

    cr_assert(init_world(&world, 5, 4) == OK);
    map = world.map;
    tile = map;
    for (int i = 0; i < 100; i++) {
        if (i % 4 == 0)
            cr_assert_eq(map, tile);
        else
            cr_assert_neq(map, tile);
        tile = tile->down;
    }
    free_map(world.map);
}

Test(check_positions, world)
{
    int width = 423;
    int height = 871;
    world_t world;
    tile_t *map;

    cr_assert(init_world(&world, width, height) == OK);
    map = world.map;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            cr_assert_eq(x, map->pos.x);
            cr_assert_eq(y, map->pos.y);
            map = map->right;
        }
        map = map->down;
    }
    free_map(world.map);
}