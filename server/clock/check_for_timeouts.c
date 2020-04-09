/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Disconnect a client if it doesn't respond early
/// \param zappy
void check_for_timeouts(zappy_t *zappy)
{
    client_t *client_tmp = zappy->server.clients;
    client_t *next;

    if (ZAPPY_NO_TIMEOUT)
        return;
    while (client_tmp) {
        next = client_tmp->base.next;
        if (client_tmp->base.timeout <= 0)
            disconnect_client(&client_tmp, &zappy->server, "timeout");
        client_tmp = next;
    }
}