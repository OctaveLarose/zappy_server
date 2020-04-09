/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by thomas
*/

#include "macros.h"
#include "errors.h"
#include "game/commands.h"

static tile_t *get_new_first_in_row(tile_t *old_first, dir_t player_dir)
{
    tile_t *new_first = get_tile_in_dir(old_first, player_dir);
    dir_t dir_to_left = get_dir_to_left(player_dir);

    if (!new_first)
        return (NULL);
    if (dir_to_left == INVALID_DIR)
        return (NULL);
    return (get_tile_in_dir(new_first, dir_to_left));
}

int fill_resp_look_row(buffer_t *buf, tile_t *first, dir_t dir_look, int i)
{
    tile_t *tmp = first;
    int len = 2 * i + 1;

    for (int j = 0; j < len; j++) {
        if (look_tile(buf, tmp) == ERR)
            return (ERR);
        tmp = get_tile_in_dir(tmp, dir_look);
        buf->str[(buf->len)++] = ',';
    }
    return (OK);
}

/// \brief Format output in a readable look server response
/// \param buf
/// \param player
/// \return status
int fill_resp_look(buffer_t *buf, player_t *player)
{
    dir_t dir_look = get_dir_to_right(player->direction);
    tile_t *first = player->tile;

    if (dir_look == INVALID_DIR)
        return (error_print("look : get_dir_to_right failed.\n"));
    buf->str[buf->len++] = '[';
    for (int i = 0; i <= player->level; i++) {
        if (i != 0)
            first = get_new_first_in_row(first, player->direction);
        if (!first)
            return (error_print("look : get_new_first_in_row failed.\n"));
        if (fill_resp_look_row(buf, first, dir_look, i) == ERR)
            return (error_print("look : fill_resp_look_row failed.\n"));
    }
    buf->str[buf->len] = '\0';
    return (OK);
}

/// \brief Get what is in the field of view of the player
/// \param cmd
/// \param player
/// \param game
/// \return status
int cmd_look(char *cmd, player_t *player, game_t *game)
{
    buffer_t buffer;
    unsigned int len;

    UNUSED(cmd);
    UNUSED(game);
    buffer.len = 0;
    if (fill_resp_look(&buffer, player) == ERR)
        return (RESP_KO);
    len = strlen(buffer.str);
    if (len == 0 || len > MAX_CMD_LEN - 2)
        return (RESP_KO);
    memcpy(buffer.str + len - 1, " ]\n\0", 4);
    if (player->client)
        add_to_buffer(buffer.str, &player->client->base.buffer_out);
    else
        return (RESP_KO);
    return (RESP_OTHER);
}