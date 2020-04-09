/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/client.h"
#include "macros.h"
#include <stdio.h>

bool remove_endline_from_command(char *str)
{
    uint16_t len = 0;

    for (; str[len] && str[len] != '\n' && len < MAX_CMD_LEN; len++);
    if (len >= MAX_CMD_LEN || str[len] == '\0') {
        dprintf(2, "Removing endline failed.\n");
        return (false);
    }
    str[len] = '\0';
    return (true);
}

int add_str_to_command(c_buffer_t *buf, char **buf_str, char *cmd, int *j)
{
    for (; *j < MAX_CMD_LEN && **buf_str && **buf_str != '\n'; (*j)++) {
        cmd[*j] = **buf_str;
        (*buf_str)++;
    }
    if (**buf_str == '\n') {
        cmd[*j] = '\0';
        (*buf_str)++;
        return (OK);
    } else if (**buf_str == '\0') {
        *buf_str = read_from_buffer(buf);
        if (!(*buf_str))
            return (ERR);
        return (NOT_DONE);
    } else {
        cmd[*j] = '\0';
        return (ERR);
    }
}

bool parse_command(c_buffer_t *buf, char commands[MAX_COMMANDS][MAX_CMD_LEN])
{
    char *buf_str = read_from_buffer(buf);
    int j = 0;
    int res;
    bool not_done = false;

    if (!buf_str)
        return (false);
    for (int i = 0; i < MAX_COMMANDS && buf_str; i++) {
        if (commands[i][0] != '\0' && !not_done)
            continue;
        res = add_str_to_command(buf, &buf_str, commands[i], &j);
        if (res == NOT_DONE) {
            i--;
            not_done = true;
        } else if (res != ERR) {
            j = 0;
            not_done = false;
        } else
            break;
    }
    return (true);
}
