/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/game.h"
#include "game/log.h"
#include "game/commands.h"
#include "macros.h"

/// \brief Allow the player to move forward
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_forward(char *cmd, player_t *player, game_t *game)
{
    int ret;

    UNUSED(cmd);
    UNUSED(game);
    ret = move_player_in_dir(player, player->direction) ? RESP_OK : RESP_KO;
    forward_log(player, &game->game_log);
    return (ret);
}

/// \brief Allow the player to move right
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_right(char *cmd, player_t *player, game_t *game)
{
    UNUSED(cmd);
    UNUSED(game);
    switch (player->direction) {
    case NORTH:
        player->direction = EAST;
        break;
    case EAST:
        player->direction = SOUTH;
        break;
    case SOUTH:
        player->direction = WEST;
        break;
    case WEST:
        player->direction = NORTH;
        break;
    default:
        return (RESP_KO);
    }
    dir_log(player, &game->game_log);
    return (0);
}

/// \brief Allow the player to move left
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_left(char *cmd, player_t *player, game_t *game)
{
    UNUSED(cmd);
    UNUSED(game);
    switch (player->direction) {
    case NORTH:
        player->direction = WEST;
        break;
    case EAST:
        player->direction = NORTH;
        break;
    case SOUTH:
        player->direction = EAST;
        break;
    case WEST:
        player->direction = SOUTH;
        break;
    default:
        return (RESP_KO);
    }
    dir_log(player, &game->game_log);
    return (RESP_OK);
}