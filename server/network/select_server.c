/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by thomas
*/

#include <stdio.h>
#include "macros.h"
#include "zappy.h"

/// \brief Allow the server to handle multiple clients concurrently
/// \param zappy
/// \param rfds
/// \param wfds
/// \return true on success, false otherwise
bool select_server(zappy_t *zappy, fd_set *rfds, fd_set *wfds)
{
    server_t *server = &zappy->server;
    client_t *next;

    server->select_timeout.tv_usec = SELECT_WAIT_USEC;
    if (select(FD_SETSIZE, rfds, wfds, NULL, &server->select_timeout) < 0) {
        perror("select");
        return (false);
    }
    if (FD_ISSET(server->socket, rfds))
        handle_new_connection(zappy);
    for (client_t *cli = server->clients; cli;) {
        next = cli->base.next;
        if (cli && FD_ISSET(cli->base.socket, wfds))
            manage_wfds(&cli, zappy);
        if (cli && FD_ISSET(cli->base.socket, rfds))
            manage_rfds(&cli, zappy);
        if (!cli)
            break;
        cli = next;
    }
    return (true);
}
