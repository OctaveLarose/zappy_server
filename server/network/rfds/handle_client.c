/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"
#include "zappy.h"

/// \brief Check if their command related to AI and execute them if the client
///        is ready
/// \param client
/// \param zappy
/// \return
bool handle_client_ai(client_ai_t **client, zappy_t *zappy)
{
    c_buffer_t *buf_in = &(*client)->base.buffer_in;

    UNUSED(zappy);
    if ((*client)->base.status == READY && has_command(buf_in))
        parse_command(buf_in, (*client)->base.commands);
    return (true);
}

bool handle_client_graphic(client_graphic_t **client, zappy_t *zappy)
{
    UNUSED(client);
    UNUSED(zappy);
    return (false);
}

/// \brief Check if client is able to get a player, otherwise it will disconnect
///        it
/// \param client
/// \param zappy
/// \param team_name
/// \return true on success, false otherwise
bool give_player_to_client_unknown(client_t **client, zappy_t *zappy, \
char *team_name)
{
    int ret = give_player_to_client((client_ai_t *)*client, &zappy->game, \
team_name);

    switch (ret) {
    case OK:
        (*client)->base.type = CLIENT_AI;
        (*client)->base.status = WAITING_SERV_INFO;
        (*client)->ai.has_player = true;
        return (true);
    case INVALID_TEAM:
        disconnect_client(client, &zappy->server, INVALID_TEAM_MSG);
        return (false);
    case TEAM_OUT_OF_SPACE:
        disconnect_client(client, &zappy->server, TEAM_OUT_OF_SPACE_MSG);
        return (false);
    case UNEXPECTED_SERVER_ERROR:
        disconnect_client(client, &zappy->server, UNEXPECTED_SERV_ERR_MSG);
        return (false);
    default:
        return (false);
    }
}

/// \brief Determine if the client is a graphic client and update
///        client structure to match it
/// \param client
/// \param zappy
/// \return
bool handle_client_unknown(client_t **client, zappy_t *zappy)
{
    char *recv = read_from_buffer(&(*client)->base.buffer_in);

    if (!recv)
        return (false);
    if (!remove_endline_from_command(recv))
        return (false);
    if ((*client)->base.status != WAITING_CLIENT_INFO)
        return (false);
    if (!strcmp(recv, CLIENT_GRAPHIC_HANDSHAKE_MSG)) {
        (*client)->base.type = CLIENT_GRAPHIC;
        (*client)->base.status = WAITING_SERV_INFO;
        return (true);
    } else {
        return (give_player_to_client_unknown(client, zappy, recv));
    }
}

/// \brief Call the specific handle function according to the client type
/// \param client
/// \param zappy
/// \return
bool handle_client(client_t **client, zappy_t *zappy)
{
    int val = recv_client_info(*client);

    if (val == 0) {
        disconnect_client(client, &zappy->server, CLOSED_CONNECTION_MSG);
        return (true);
    }
    reset_client_timer(*client);
    switch ((*client)->base.type) {
    case CLIENT_AI:
        return (handle_client_ai((client_ai_t **)client, zappy));
    case CLIENT_GRAPHIC:
        return (handle_client_graphic((client_graphic_t **)client, zappy));
    default:
        return (handle_client_unknown(client, zappy));
    }
}
