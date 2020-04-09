/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "circular_buffer.h"

/// \brief Get free space in buffer
/// \param buffer
/// \return free space left
int get_len_left(c_buffer_t *buffer)
{
    return (CIRCULAR_BUFFER_LEN - buffer->write_offset - 1);
}

/// \brief Check if given data will fit in the buffer
/// \param len
/// \param buffer
/// \return true if small enough
bool can_fit_in_buffer(int len, c_buffer_t *buffer)
{
    return (get_len_left(buffer) > len);
}

/// \brief Add data to the buffer
/// \param str
/// \param buffer
/// \return length of the added content, ADD_FAIL on error
int add_to_buffer(char *str, c_buffer_t *buffer)
{
    int len_str = strlen(str);
    int len_left = get_len_left(buffer);

    if (len_str + buffer->nbr_bytes > CIRCULAR_BUFFER_LEN - 2)
        return (ADD_FAIL);
    if (can_fit_in_buffer(len_str, buffer)) {
        memcpy(buffer->buffer + buffer->write_offset, str, len_str + 1);
        buffer->write_offset += len_str;
        buffer->nbr_bytes += len_str;
        return (len_str);
    }
    memcpy(buffer->buffer + buffer->write_offset, str, len_left);
    str += len_left;
    buffer->nbr_bytes += len_left;
    buffer->write_offset = 0;
    if (*str)
        add_to_buffer(str, buffer);
    return (len_str);
}