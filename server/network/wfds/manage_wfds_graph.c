/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "macros.h"

/// \brief Send the world info if the graphic need it, and send game logs
///        otherwise
/// \param client
/// \param zappy
/// \return
int handle_client_graph_wfds(client_t **client, zappy_t *zappy)
{
    buffer_t *game_log = &zappy->game.game_log;
    int ret;

    if ((*client)->base.status == WAITING_SERV_INFO) {
        reset_buffer(game_log);
        ret = send_init_info_to_graph(&(*client)->graphic, &zappy->game);
        printf(CLIENT_GRAPHIC_READY_MSG, (*client)->base.socket);
        (*client)->base.status = READY;
        return (ret);
    }
    if (game_log->str[0] != '\0' && (*client)->base.status == READY) {
        ret = send_info_to_graphical(&(*client)->graphic, game_log->str);
        reset_buffer(game_log);
        return (ret);
    }
    return (OK);
}
