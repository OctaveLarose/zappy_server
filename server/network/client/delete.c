/*
** EPITECH PROJECT, 2018
** PSU_zappy_2018
** File description:
** Delete and remove_clients
*/

#include <stdio.h>
#include "network/client.h"
#include "network/server.h"

/// \brief Close the client file descriptor and free the memory allocated for
///        the client
/// \param client
void free_client(client_t *client)
{
    if (client->base.socket != -1)
        close(client->base.socket);
    if (client->base.type == CLIENT_AI && ((client_ai_t *) client)->player)
        ((client_ai_t *) client)->player->client = NULL;
    free(client);
}

void free_all_clients(client_t *client)
{
    client_t *tmp = client;
    client_t *next;

    while (tmp) {
        next = tmp->base.next;
        free_client(tmp);
        tmp = next;
    }
}

/// \brief Remove the client corresponding to the given file descriptor from
///        the given clients linked list
/// \param first
/// \param fd
void delete_client(client_t **first, int fd)
{
    client_t *prev = NULL;
    client_t *idx = *first;
    client_t *next = NULL;

    if (idx != NULL && idx->base.socket == fd) {
        *first = idx->base.next;
        free_client(idx);
        return;
    }
    while (idx != NULL && idx->base.socket != fd) {
        prev = idx;
        idx = idx->base.next;
        next = idx->base.next;
    }
    if (idx == NULL)
        return;
    prev->base.next = next;
    free_client(idx);
}

/// \brief Remove a client from the fdsets (it won't be able to communicate)
///        and delete it
/// \param client
/// \param server
/// \param reason
void disconnect_client(client_t **client, server_t *server, const char *reason)
{
    client_t *cl = *client;
    client_t *tmp_next = (*client)->base.next;

    fprintf(stderr, "Client with fd %d was disconnected. ", cl->base.socket);
    fprintf(stderr, "Reason : %s\n", reason);
    if (FD_ISSET(cl->base.socket, &server->perm_rfds))
        FD_CLR(cl->base.socket, &server->perm_rfds);
    if (FD_ISSET(cl->base.socket, &server->wfds))
        FD_CLR(cl->base.socket, &server->wfds);
    if (FD_ISSET(cl->base.socket, &server->tmp_rfds))
        FD_CLR(cl->base.socket, &server->tmp_rfds);
    if (cl->ai.player)
        cl->ai.player->client = NULL;
    delete_client(&server->clients, cl->base.socket);
    *client = tmp_next;
}