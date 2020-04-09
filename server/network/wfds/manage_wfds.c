/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "network/server.h"
#include "macros.h"

/// \brief Handle the while progress of a client, sent it welcome and
///        map information on connection, and redirect after depending
///        on his type
/// \param client
/// \param zappy
/// \return status (ADD_FAIL, ERR, OK)
int handle_client_wfds(client_t **client, zappy_t *zappy)
{
    c_buffer_t *buf_out = &(*client)->base.buffer_out;

    if ((*client)->base.status == WAITING_WELCOME) {
        if (add_to_buffer("WELCOME\n", buf_out) == ADD_FAIL)
            return (ERR);
        (*client)->base.status = WAITING_CLIENT_INFO;
    }
    if ((*client)->base.type == CLIENT_AI)
        return (handle_client_ai_wfds(client, zappy));
    else if ((*client)->base.type == CLIENT_GRAPHIC)
        return (handle_client_graph_wfds(client, zappy));
    else
        return (respond_to_client(*client) ? OK : ERR);
}

/// \brief Check if the handle_client_wfds returned an error, of if the client
///        is a valid one
/// \param client
/// \param zappy
/// \return
int manage_wfds(client_t **client, zappy_t *zappy)
{
    int ret;

    if (client) {
        ret = handle_client_wfds(client, zappy);
        if (ret == ERR)
            disconnect_client(client, &zappy->server, "Couldn't send msg.");
        return (ret);
    } else
        return (ERR);
}