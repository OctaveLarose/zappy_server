/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "macros.h"
#include "network/server.h"

bool handle_new_connection(zappy_t *zappy)
{
    server_t *server = &zappy->server;
    client_t *client;

    client = accept_client(server);
    if (!client || !append_to_client_list(&server->clients, client))
        return (false);
    return (true);
}

int manage_rfds(client_t **client, zappy_t *zappy)
{
    if (client)
        return (handle_client(client, zappy) ? OK : ERR);
    else
        return (ERR);
}