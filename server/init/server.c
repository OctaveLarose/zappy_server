/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "macros.h"
#include "errors.h"
#include "network/server.h"

/// \brief Bind the socket to the selected port
/// \param sock_addr
/// \param socket
/// \param port
/// \return
int init_sock_address(struct sockaddr_in *sock_addr, int socket, int port)
{
    socklen_t socklen = sizeof(struct sockaddr_in);

    sock_addr->sin_family = AF_INET;
    sock_addr->sin_addr.s_addr = INADDR_ANY;
    sock_addr->sin_port = htons(port);
    if (bind(socket, ((struct sockaddr *) (sock_addr)), socklen) < 0)
        return (error("bind"));
    return (OK);
}

/// \brief Setup select's fdsets
/// \param server
void init_select(server_t *server)
{
    FD_ZERO(&server->perm_rfds);
    FD_ZERO(&server->wfds);
    FD_SET(server->socket, &server->perm_rfds);
    server->select_timeout.tv_sec = 0;
    server->select_timeout.tv_usec = 0;
}

/// \brief Create the socket and setup the listening port
/// \param server
/// \param port
/// \return
int init_server(server_t *server, int port)
{
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == -1)
        return (error("socket"));
    if (init_sock_address(&server->sockaddr, server->socket, port) == ERR)
        return (ERR);
    if (listen(server->socket, LISTEN_MAX_CLIENT) == -1)
        return (error("listen"));
    server->port = port;
    server->clients = NULL;
    init_select(server);
    return (OK);
}