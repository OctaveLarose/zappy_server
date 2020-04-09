/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/server.h"
#include "macros.h"
#include "errors.h"

int get_socket_client(int serv_socket, struct sockaddr_in *sock_addr)
{
    int new_socket;
    int addr_len = sizeof(struct sockaddr_in);
    struct sockaddr *casted_sa = (struct sockaddr *) sock_addr;

    new_socket = accept(serv_socket, casted_sa, (socklen_t *) &addr_len);
    if (new_socket < 0) {
        perror("accept");
        return (-1);
    }
    if (new_socket >= FD_SETSIZE) {
        dprintf(2, "Out of room for clients (FD_SETSIZE reached)\n");
        return (-1);
    }
    return (new_socket);
}

/// \brief Accept (socket), create a client and add the client fd to the
///        read and write fdsets
/// \param server
/// \return A pointer to the new client
client_t *accept_client(server_t *server)
{
    int new_socket = get_socket_client(server->socket, &server->sockaddr);
    client_t *client;

    if (new_socket < 0)
        return (NULL);
    client = create_client(new_socket);
    if (!client)
        return (NULL);
    FD_SET(new_socket, &server->perm_rfds);
    FD_SET(new_socket, &server->wfds);
    printf("Connection from %s:", inet_ntoa(server->sockaddr.sin_addr));
    printf("%d\n", ntohs(server->sockaddr.sin_port));
    return (client);
}