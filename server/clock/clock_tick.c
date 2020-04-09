/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "game/log.h"
#include "zappy.h"

/// \brief Update client timeout
/// \param client
/// \param time_diff
void clock_tick_clients(client_t *client, clock_t time_diff)
{
    client_t *client_tmp = client;

    while (client_tmp != NULL) {
        client_tmp->base.timeout -= time_diff;
        client_tmp = client_tmp->base.next;
    }
}

/// \brief Check if player have enough and otherwise kill it
/// \param player
/// \param game
/// \param ttf
/// \return 1 if the player died, 0 otherwise
int clock_tick_player_ttl(player_t **player, game_t *game, int ttf)
{
    int new_food_val;
    client_ai_t *cli = (*player)->client;

    if (ttf == 0)
        return (ERR);
    new_food_val = (*player)->ttl / ttf;
    if (new_food_val < (*player)->inventory.food)
        (*player)->inventory.food = new_food_val;
    if ((*player)->ttl <= 0) {
        printf("Player %d died.\n", (*player)->id);
        kill_log(*player, &game->game_log);
        if (cli) {
            cli->player = NULL;
            cli->has_player = false;
        }
        delete_player(player, &game->players);
        return (OK);
    }
    return (OK);
}

/// \brief Loop over all players and update their food
/// \param game
/// \param time_diff
/// \param f
void clock_tick_players(game_t *game, clock_t time_diff, double f)
{
    player_t *player_tmp = game->players;
    player_t *next;
    double ttl_to_food = TIME_UNITS_PER_FOOD / f * SECOND_NBR;

    while (player_tmp) {
        next = player_tmp->next_player;
        if (player_tmp->client && player_tmp->client->base.status != READY) {
            player_tmp = next;
            continue;
        }
        if (player_tmp->action_time_left > 0)
            player_tmp->action_time_left -= time_diff;
        if (player_tmp->ttl > 0)
            player_tmp->ttl -= time_diff;
        clock_tick_player_ttl(&player_tmp, game, ttl_to_food);
        player_tmp = next;
    }
}

/// \brief Update game time
/// \param zappy
/// \param time_start
void clock_tick(zappy_t *zappy, clock_t time_start)
{
    clock_t cur_time = clock();
    clock_t time_diff;

    if (time_start == (clock_t)-1) {
        fprintf(stderr, "Time couldn't tick down : time_start is incorrect.");
        return;
    } else if (cur_time == (clock_t)-1) {
        fprintf(stderr, "Time couldn't tick down : cur_time is incorrect.");
        return;
    }
    time_diff = cur_time - time_start;
    clock_tick_clients(zappy->server.clients, time_diff);
    clock_tick_players(&zappy->game, time_diff, zappy->game.freq);
}