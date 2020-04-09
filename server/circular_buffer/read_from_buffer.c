/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "circular_buffer.h"

/// \brief Check if the buffer contain something
/// \param buffer
/// \return true if not empty
bool is_buf_readable(c_buffer_t *buffer)
{
    if (buffer->nbr_bytes <= 0)
        return (false);
    return (true);
}

/// \brief Check if not empty and get a valid command from it
/// \param buffer
/// \return a valid command
char *read_from_buffer(c_buffer_t *buffer)
{
    char *ptr = buffer->buffer + buffer->read_offset;
    int len_ptr = strlen(ptr);

    if (!is_buf_readable(buffer))
        return (NULL);
    if (buffer->write_offset < buffer->read_offset)
        buffer->read_offset = 0;
    else
        buffer->read_offset = buffer->write_offset;
    buffer->nbr_bytes -= len_ptr;
    if (buffer->nbr_bytes < 0)
        buffer->nbr_bytes = 0;
    return (ptr);
}