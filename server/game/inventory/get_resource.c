/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/game.h"
#include "game/inventory.h"

/// \brief Get a random resource between the all available ones
/// \return a random food
resource_t get_random_resource(void)
{
    int nbr = NB_RESOURCES + FOOD_EXTRA_SPAWN_RATE;
    int rand_nbr = rand() % nbr;

    if (rand_nbr >= 7)
        return (FOOD);
    else
        return (rand_nbr);
}

/// \brief Convert a string to his resource_t equivalent
/// \param str
/// \return the resource
resource_t get_resource_from_str(char *str)
{
    char *res_str[] = {RESOURCES_STR};

    for (int i = 0; i < NB_RESOURCES; i++) {
        if (strcmp(str, res_str[i]) == 0)
            return (i);
    }
    return (INVALID_RES);
}