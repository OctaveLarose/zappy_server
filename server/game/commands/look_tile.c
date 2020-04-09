/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "macros.h"
#include "game/commands.h"
#include "errors.h"

int look_print(buffer_t *buffer, uint16_t content, char *name)
{
    int len = strlen(name);

    for (int i = 0; i < content; i++) {
        if (buffer->len + len + 1 >= MAX_CMD_LEN)
            return (ERR);
        memcpy(buffer->str + (buffer->len++), " ", 1);
        memcpy(buffer->str + buffer->len, name, len);
        buffer->len += len;
    }
    return (OK);
}

/// \brief Fill the buffer with the corresponding number of " players" string
/// \param buffer
/// \param tile
/// \return
int look_print_player(buffer_t *buffer, tile_t *tile)
{
    player_t *current = tile->players;
    int len = strlen(" player");

    for (; current; current = current->next_neighbor) {
        if (current->level == EGG)
            continue;
        if (buffer->len + len >= MAX_CMD_LEN)
            return (ERR);
        memcpy(buffer->str + buffer->len, " player", len);
        buffer->len += len;
    }
    return (OK);
}

/// \brief Fill the buffer with the content of the given tile
/// \param buffer
/// \param tile
/// \return
int look_tile(buffer_t *buffer, tile_t *tile)
{
    char *res_str[] = {RESOURCES_STR};
    uint16_t *inv_arr = (uint16_t *) (&tile->inventory);

    if (look_print_player(buffer, tile) == ERR)
        return (error_print("look : look_print_player failed.\n"));
    for (int i = 0; i < NB_RESOURCES; i++) {
        if (look_print(buffer, inv_arr[i], res_str[i]) == ERR)
            return (error_print("look : look_print failed.\n"));
    }
    return (OK);
}
