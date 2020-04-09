/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "macros.h"
#include "game/log.h"
#include "game/commands.h"

/// \brief Remove an item from the ground and add it to the player inventory
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_take(char *cmd, player_t *player, game_t *game)
{
    char *arg = strtok(cmd, " ");
    resource_t res;
    int val;

    UNUSED(game);
    if (!arg)
        return (RESP_KO);
    arg = strtok(NULL, " ");
    if (!arg)
        return (RESP_KO);
    res = get_resource_from_str(arg);
    if (res == INVALID_RES)
        return (RESP_KO);
    val = transfer_item(&player->tile->inventory, &player->inventory, res);
    if (res == FOOD)
        player->ttl += (TIME_UNITS_PER_FOOD / game->freq * SECOND_NBR);
    if (val)
        take_log(player->id, res, &game->game_log);
    return (val ? RESP_OK : RESP_KO);
}

/// \brief Remove an item from the player inventory and add it to the ground
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_set(char *cmd, player_t *player, game_t *game)
{
    char *arg = strtok(cmd, " ");
    resource_t res;
    int val;

    UNUSED(game);
    if (!arg)
        return (RESP_KO);
    arg = strtok(NULL, " ");
    if (!arg)
        return (RESP_KO);
    res = get_resource_from_str(arg);
    if (res == INVALID_RES)
        return (RESP_KO);
    val = transfer_item(&player->inventory, &player->tile->inventory, res);
    if (val)
        spawn_resource_log(&player->tile->pos, res, &game->game_log);
    return (val ? RESP_OK : RESP_KO);
}
