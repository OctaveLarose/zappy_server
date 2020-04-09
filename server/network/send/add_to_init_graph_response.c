/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Output a string to the buffer that'll be sent to the graphic client
/// \param str
/// \param client
/// \return
int add_to_init_graph_response(char *str, client_graphic_t *client)
{
    if (add_to_buffer(str, &client->base.buffer_out) != ADD_FAIL)
        return (OK);
    if (respond_to_client((client_t *) client) == false)
        return (ADD_FAIL);
    if (add_to_buffer(str, &client->base.buffer_out) == ADD_FAIL)
        return (ADD_FAIL);
    else
        return (OK);
}