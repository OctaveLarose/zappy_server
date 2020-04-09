/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Remove all data from a buffer
/// \param buffer
void reset_buffer(buffer_t *buffer)
{
    memset(buffer, 0, MAX_CMD_LEN);
    buffer->len = 0;
}

/// \brief Append data into a buffer
/// \param str
/// \param buffer
/// \return true on success
bool add_str_to_buffer(char *str, buffer_t *buffer)
{
    int len_str = strlen(str);

    if (buffer->len + len_str > MAX_CMD_LEN - 2)
        return (false);
    strncpy(buffer->str + buffer->len, str, len_str + 1);
    buffer->len += len_str;
    return (true);
}