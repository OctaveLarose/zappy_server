/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include <stdint-gcc.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define NB_RESOURCES 7

typedef enum resource {
    INVALID_RES = -1,
    FOOD = 0,
    LINEMATE = 1,
    DERAUMERE = 2,
    SIBUR = 3,
    MENDIANE = 4,
    PHIRAS = 5,
    THYSTAME = 6
} resource_t;

#define RESOURCES_STR "food", "linemate", "deraumere", "sibur", "mendiane", \
"phiras", "thystame"

typedef struct s_inventory
{
    uint16_t food;
    uint16_t linemate;
    uint16_t deraumere;
    uint16_t sibur;
    uint16_t mendiane;
    uint16_t phiras;
    uint16_t thystame;
} inventory_t;

bool add_resource_to_inventory(inventory_t *inventory, resource_t);
bool del_resource_from_inventory(inventory_t *inventory, resource_t);
bool transfer_item(inventory_t *inv_from, inventory_t *inv_to, resource_t);
resource_t get_random_resource(void);
resource_t get_resource_from_str(char *str);
bool check_ritual_resources(const inventory_t *, const inventory_t *);

#endif