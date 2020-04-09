/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "macros.h"

#include "game/commands.h"
#include "game/game.h"
#include "game/log.h"

/// \brief Send a notification that an incantation has started to all clients
/// \param players
void send_ritual_start_msg_to_players(player_t *players)
{
    c_buffer_t *buffer_out;

    for (player_t *tmp = players; tmp; tmp = tmp->next_neighbor) {
        tmp->in_incantation = true;
        if (tmp->client) {
            buffer_out = &tmp->client->base.buffer_out;
            add_to_buffer(ELEVATION_UNDERWAY_MSG, buffer_out);
        }
    }
}

/// \brief Check prerequisites and therefore call the actual incantation
/// \param player
/// \param game_log
/// \return
int set_incantation_command(player_t *player, buffer_t *game_log)
{
    int ret;

    if (player->level < 1 || player->level > 7)
        return (ERR);
    ret = check_if_ritual_req_met(&ritual_data[player->level - 1], player);
    if (ret) {
        send_ritual_start_msg_to_players(player->tile->players);
        incantation_start_log(&player->tile->pos, game_log);
        return (OK);
    } else {
        player->action_time_left = 0;
        player->cur_action = NULL;
        add_to_buffer("ko\n", &player->client->base.buffer_out);
        return (ERR);
    }
}

int set_command(char *cmd, player_t *player, double f, buffer_t *game_log)
{
    for (int i = 0; command_list[i].name != NULL; i++) {
        if (strcmp_until_space(cmd, command_list[i].name) != 0)
            continue;
        player->cur_action = cmd;
        player->action_time_left = command_list[i].time_limit / f * SECOND_NBR;
        if (i == INCANTATION_CMD_IDX)
            return (set_incantation_command(player, game_log));
        return (OK);
    }
    dprintf(2, "Wrong command : %s\n", cmd);
    add_to_buffer("ko\n", &player->client->base.buffer_out);
    return (ERR);
}

bool set_player_command(player_t *player, double freq, buffer_t *game_log)
{
    char *command;

    if (!player->client)
        return (false);
    for (int i = 0; i < MAX_COMMANDS; i++) {
        command = player->client->base.commands[i];
        if (command[0] == '\0')
            continue;
        if (set_command(command, player, freq, game_log) == ERR) {
            command[0] = '\0';
            return (false);
        }
        return (true);
    }
    return (false);
}