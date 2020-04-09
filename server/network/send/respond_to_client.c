/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/server.h"

/// \brief Send the content of the buffer to the client
/// \param client
/// \return true if sent, false otherwise
bool respond_to_client(client_t *client)
{
    char *to_send;

    while (is_buf_readable(&client->base.buffer_out)) {
        to_send = read_from_buffer(&client->base.buffer_out);
        if (!to_send || !to_send[0])
            return (false);
        if (send(client->base.socket, to_send, strlen(to_send), 0) == -1)
            return (false);
    }
    return (true);
}