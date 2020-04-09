/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "circular_buffer.h"

/// \brief Check if the buffer contain a valid command
/// \param buffer
/// \return
bool has_command(c_buffer_t *buffer)
{
    char *str = buffer->buffer;
    int tmp_offset = buffer->read_offset;

    for (int i = 0; i < buffer->nbr_bytes; i++) {
        if (*(str + tmp_offset) == '\n')
            return (true);
        tmp_offset++;
        if (tmp_offset >= CIRCULAR_BUFFER_LEN - 1)
            tmp_offset = 0;
    }
    return (false);
}