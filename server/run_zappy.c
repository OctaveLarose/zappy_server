/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Main loop of the game
/// \param zappy
/// \return ERR or GAME_WIN
int run_zappy(zappy_t *zappy)
{
    clock_t time_start;
    bool is_running = true;

    printf("Server is running.\n");
    while (is_running) {
        time_start = clock();
        check_for_timeouts(zappy);
        set_wfds(&zappy->server, zappy->game.game_log.str);
        zappy->server.tmp_rfds = zappy->server.perm_rfds;
        if (!select_server(zappy, &zappy->server.tmp_rfds, \
&zappy->server.wfds))
            break;
        if (update_game(&zappy->game) == GAME_WIN)
            return (GAME_WIN);
        clock_tick(zappy, time_start);
    }
    return (ERR);
}