/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include <stdio.h>
#include <ctype.h>
#include "macros.h"
#include "game/game.h"
#include "game/commands.h"

/// \brief A custom strcmp that that stop at the next space it find
/// \param s1
/// \param s2
/// \return
int strcmp_until_space(char *s1, char *s2)
{
    int i;

    for (i = 0; s2[i] != 0 && s1[i] != ' '; i++) {
        if (tolower(s1[i]) == tolower(s2[i]))
            continue;
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
    }
    if (s1[i] == ' ')
        return (0);
    return (s1[i] - s2[i]);
}

/// \brief Apply commands to the player
/// \param cmd
/// \param player
/// \param game
/// \return
int execute_player_command(char *cmd, player_t *player, game_t *game)
{
    int ret;

    for (int i = 0; command_list[i].name != NULL; i++) {
        if (strcmp_until_space(cmd, command_list[i].name) == 0) {
            ret = command_list[i].cmd_ptr(cmd, player, game);
            cmd[0] = '\0';
            return (ret);
        }
    }
    dprintf(2, "Wrong command : %s\n", cmd);
    return (ERR);
}

bool fill_response_to_client(c_buffer_t *buffer_response, int val)
{
    if (val == RESP_OK)
        return (add_to_buffer("ok\n", buffer_response));
    else if (val == RESP_KO)
        return (add_to_buffer("ko\n", buffer_response));
    return (false);
}