/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "zappy.h"

void free_zappy(zappy_t *zappy)
{
    if (zappy->game.teams)
        free_team_array(zappy->game.teams);
    if (zappy->game.world.map)
        free_map(zappy->game.world.map);
    if (zappy->server.socket != -1)
        close(zappy->server.socket);
    if (zappy->game.players)
        free_all_players(zappy->game.players);
    if (zappy->server.clients)
        free_all_clients(zappy->server.clients);
}

/// \brief Global initialization function, call game and server ones
/// \param zappy
/// \param args
/// \return
int init_zappy(zappy_t *zappy, arg_holder_t *args)
{
    memset(zappy, 0, sizeof(zappy_t));
    if (init_game(&zappy->game, args) == ERR)
        return (ERR);
    if (init_server(&zappy->server, args->port) == ERR)
        return (ERR);
    return (OK);
}