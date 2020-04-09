/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "circular_buffer.h"

/// \brief Setup default buffer parameters
/// \param buffer
void init_c_buffer(c_buffer_t *buffer)
{
    buffer->read_offset = 0;
    buffer->write_offset = 0;
    buffer->nbr_bytes = 0;
}