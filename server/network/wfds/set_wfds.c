/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/server.h"

void if_set_wfds(client_t *client, fd_set *perm_wfds, char *game_log)
{
    client_status_t status = client->base.status;

    if (status == WAITING_WELCOME || status == WAITING_SERV_INFO)
        return;
    if (client->base.type == CLIENT_GRAPHIC && game_log[0] == '\0') {
        FD_CLR(client->base.socket, perm_wfds);
        return;
    }
    if (!has_command(&client->base.buffer_out))
        FD_CLR(client->base.socket, perm_wfds);
}

void if_not_set_wfds(client_t *client, fd_set *perm_wfds, char *game_log)
{
    client_status_t status = client->base.status;

    if (status == WAITING_WELCOME || status == WAITING_SERV_INFO) {
        FD_SET(client->base.socket, perm_wfds);
        return;
    }
    if (has_command(&client->base.buffer_out)) {
        FD_SET(client->base.socket, perm_wfds);
        return;
    }
    if (client->base.type == CLIENT_GRAPHIC && game_log[0] != '\0') {
        FD_SET(client->base.socket, perm_wfds);
        return;
    }
}

/// \brief Allow clients to get data from server by adding them
///        in the write file descriptor set
/// \param server
/// \param game_log
void set_wfds(server_t *server, char *game_log)
{
    client_t *tmp = server->clients;

    while (tmp != NULL) {
        if (FD_ISSET(tmp->base.socket, &server->wfds))
            if_set_wfds(tmp, &server->wfds, game_log);
        if (!FD_ISSET(tmp->base.socket, &server->wfds))
            if_not_set_wfds(tmp, &server->wfds, game_log);
        tmp = tmp->base.next;
    }
}