/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/


#include "game/commands.h"
#include "macros.h"

char *dir_to_str(dir_t dir)
{
    char *dir_str[] = {DIR_STR};

    if (dir < 0 || dir > 3)
        return (NULL);
    return (dir_str[dir]);
}

bool init_eject_msg(player_t *player, dir_t dir)
{
    char msg_buffer[15];
    char *dir_str = dir_to_str(dir);

    if (!dir_str)
        return (false);
    sprintf(msg_buffer, "eject : %s\n", dir_str);
    add_to_buffer(msg_buffer, &player->client->base.buffer_out);
    return (true);
}

/// \brief Eject a player from his tile
/// \param cmd
/// \param player
/// \param game
/// \return
int cmd_eject(char *cmd, player_t *player, game_t *game)
{
    player_t *tmp = player->tile->players;
    player_t *next;

    UNUSED(cmd);
    UNUSED(game);
    while (tmp) {
        if (tmp == player) {
            tmp = tmp->next_neighbor;
            continue;
        }
        next = tmp->next_neighbor;
        if (!move_player_in_dir(tmp, player->direction))
            return (RESP_KO);
        player->in_incantation = false;
        if (tmp->client && !init_eject_msg(tmp, player->direction))
            return (RESP_KO);
        tmp = next;
    }
    return (RESP_OK);
}