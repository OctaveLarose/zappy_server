/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "network/server.h"
#include "macros.h"

/// \brief Fill the client out buffer with map size and client ID
/// \param client
/// \param world
void init_serv_info_buffer(client_ai_t *client, world_t *world)
{
    char buf[40];
    int x = world->width;
    int y = world->height;
    int clients_num = 0;

    if (client->player && client->player->team) {
        clients_num = client->player->team->clients_num;
        clients_num += get_team_nbr_players_free(client->player->team);
        clients_num -= get_team_nbr_players_not_free(client->player->team);
    }
    sprintf(buf, "%d\n%d %d\n", clients_num, x, y);
    add_to_buffer(buf, &client->base.buffer_out);
}

/// \brief Send world info to the AI client
/// \param client
/// \param zappy
/// \return
int handle_client_ai_wfds(client_t **client, zappy_t *zappy)
{
    int ret;
    player_t *player = (*client)->ai.player;

    if ((*client)->base.status == WAITING_SERV_INFO) {
        init_serv_info_buffer((client_ai_t *) *client, &zappy->game.world);
        printf(CLIENT_AI_READY_MSG, (*client)->base.socket);
        (*client)->base.status = READY;
    }
    ret = respond_to_client(*client);
    if ((*client)->base.status == READY && player && player->ttl <= 0) {
        delete_player(&(*client)->ai.player, &zappy->game.players);
        disconnect_client(client, &zappy->server, "Player died.");
        return (OK);
    }
    return (ret);
}