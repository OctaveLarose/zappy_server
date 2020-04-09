/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Get all together in order to tell the graphic about players
/// \param players
/// \param client
/// \return
static int init_players_info(player_t *players, client_graphic_t *client)
{
    char buf[70];
    int ret = 0;
    vec2i_t *pos;

    for (player_t *tmp = players; tmp; tmp = tmp->next_player) {
        pos = &tmp->tile->pos;
        memset(buf, 0, 70);
        sprintf(buf, "%d:%d,%d:%d:%d:", tmp->id, pos->x, pos->y, \
tmp->direction, tmp->level);
        if (add_to_init_graph_response(buf, client))
            return (ERR);
        if (add_to_init_graph_response(tmp->team->name, client))
            return (ERR);
        if (tmp->next_player)
            ret = add_to_init_graph_response(";", client);
        if (ret == ADD_FAIL)
            return (ERR);
    }
    if (add_to_init_graph_response("\n", client) == ADD_FAIL)
        return (ERR);
    return (OK);
}

static int init_tile_info(tile_t *tile, client_graphic_t *client)
{
    char int_buf[15];
    uint16_t *inv = (uint16_t *) &tile->inventory;
    int ret = 0;

    memset(int_buf, 0, 15);
    for (unsigned int i = 0; i < NB_RESOURCES; i++) {
        sprintf(int_buf, "%d", inv[i]);
        if (add_to_init_graph_response(int_buf, client) == ADD_FAIL)
            return (ERR);
        if (i != NB_RESOURCES - 1)
            ret = add_to_init_graph_response(",", client);
        if (ret == ADD_FAIL)
            return (ERR);
    }
    return (OK);
}

static int init_map_info(world_t *world, client_graphic_t *client)
{
    int ret = 0;
    tile_t *tile = world->map;
    unsigned int map_size = world->width * world->height;

    for (unsigned int i = 0; i < map_size; i++) {
        if (init_tile_info(tile, client) == ERR) {
            dprintf(2, "send_init_info_to_graph failed (init_tile_info).\n");
            return (ERR);
        }
        if (i != map_size - 1)
            ret = add_to_init_graph_response(";", client);
        if (ret == ADD_FAIL)
            return (ERR);
        if (tile->pos.x == (int) world->width - 1)
            tile = tile->down;
        tile = tile->right;
    }
    if (add_to_init_graph_response("\n", client) == ADD_FAIL)
        return (ERR);
    return (OK);
}

static int init_team_info(team_t *teams, client_graphic_t *client)
{
    int ret = 0;

    for (int i = 0; teams[i].name; i++) {
        if (add_to_init_graph_response(teams[i].name, client) == ADD_FAIL)
            return (ERR);
        if (teams[i + 1].name)
            ret = add_to_init_graph_response(",", client);
        if (ret == ADD_FAIL)
            return (ERR);
    }
    if (add_to_init_graph_response("\n", client) == ADD_FAIL)
        return (ERR);
    return (OK);
}

bool send_init_info_to_graph(client_graphic_t *client, game_t *game)
{
    char buf[25];
    int og_woffset = client->base.buffer_out.write_offset;

    memset(buf, 0, 25);
    sprintf(buf, "%d,%d\n", game->world.width, game->world.height);
    if (add_to_init_graph_response(buf, client) == ADD_FAIL) {
        dprintf(2, "send_init_info_to_graph failed (add_to_init...).\n");
        return (false);
    }
    if (init_team_info(game->teams, client) == ERR || \
init_map_info(&game->world, client) == ERR || \
init_players_info(game->players, client) == ERR) {
        client->base.buffer_out.write_offset = og_woffset;
        dprintf(2, "send_init_info_to_graph failed (in init_X).\n");
        return (false);
    }
    return (respond_to_client((client_t *) client));
}