/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include <stdio.h>
#include "network/client.h"

/// \brief Push a client into the given client linked list
/// \param first
/// \param client
/// \return true if success, false otherwise
bool append_to_client_list(client_t **first, client_t *client)
{
    client_t *last;

    if (first == NULL) {
        dprintf(2, "Couldn't append client to client list\n");
        return (false);
    }
    last = get_last_client(*first);
    if (last == NULL)
        *first = client;
    else
        last->base.next = client;
    client->base.next = NULL;
    return (true);
}