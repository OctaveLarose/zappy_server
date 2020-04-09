/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Tell the graphic to take a resource
/// \param player_id
/// \param res
/// \param game_log
/// \return
int take_log(int player_id, resource_t res, buffer_t *game_log)
{
    char str[30];

    sprintf(str, "tak %d %d\n", player_id, res);
    return (add_str_to_buffer(str, game_log));
}

int take_log_inventory(const inventory_t *inv, int player_id, \
buffer_t *game_log)
{
    uint16_t *inv_arr = (uint16_t *)inv;
    int res = true;
    char str[30];

    for (int i = 0; i < NB_RESOURCES; i++) {
        for (int j = 0; j < inv_arr[i]; j++) {
            sprintf(str, "tak %d %d\n", player_id, i);
            res = add_str_to_buffer(str, game_log);
        }
        if (res == false)
            return (false);
    }
    return (res);
}