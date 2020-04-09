/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/client.h"
#include "errors.h"

/// \brief Allocate a client and setup base state
/// \param socket
/// \return a pointer to the allocated client
client_t *create_client(int socket)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return (error_print_ptr("malloc failed in create_client()"));
    client->base.type = CLIENT_UNKNOWN;
    client->base.socket = socket;
    client->base.status = WAITING_WELCOME;
    client->base.timeout = INACTIVE_TIMEOUT;
    client->base.next = NULL;
    return (client);
}