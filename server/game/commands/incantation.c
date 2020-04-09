/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"
#include "game/commands.h"
#include "game/map.h"
#include "macros.h"

const ritual_data_t ritual_data[] = { \
{.level = 1, .nb_players = 1, .inv = (inventory_t){0, 1, 0, 0, 0, 0, 0}}, \
{.level = 2, .nb_players = 2, .inv = (inventory_t){0, 1, 1, 1, 0, 0, 0}}, \
{.level = 3, .nb_players = 2, .inv = (inventory_t){0, 2, 0, 1, 0, 2, 0}}, \
{.level = 4, .nb_players = 4, .inv = (inventory_t){0, 1, 1, 2, 0, 1, 0}}, \
{.level = 5, .nb_players = 4, .inv = (inventory_t){0, 1, 2, 1, 3, 0, 0}}, \
{.level = 6, .nb_players = 6, .inv = (inventory_t){0, 1, 2, 3, 0, 1, 0}}, \
{.level = 7, .nb_players = 6, .inv = (inventory_t){0, 2, 2, 2, 2, 2, 1}}};

/// \brief Check if the given player meet the given requirements
/// \param req
/// \param player
/// \return true or false
bool check_if_ritual_req_met(const ritual_data_t *req, player_t *player)
{
    inventory_t *tile_inv = &player->tile->inventory;
    int nbr_lvl;
    int nbr_tile;

    if (!check_ritual_resources(tile_inv, &req->inv))
        return (false);
    nbr_lvl = get_nbr_players_of_lvl_on_tile(player->tile, player->level);
    nbr_tile = get_nbr_players_on_tile(player->tile);
    if (nbr_lvl != nbr_tile || nbr_lvl != req->nb_players)
        return (false);
    return (true);
}

/// \brief Run over all players to increase their level after a successful
///        incantation
/// \param tile_players
/// \param last_lvl
void upgrade_ritual_players(player_t *tile_players, int last_lvl)
{
    char buf_resp[30];

    sprintf(buf_resp, "Current level: %d\n", last_lvl + 1);
    for (player_t *tmp = tile_players; tmp; tmp = tmp->next_neighbor) {
        if (tmp->level == last_lvl && tmp->client)
            add_to_buffer(buf_resp, &tmp->client->base.buffer_out);
        if (tmp->level == last_lvl)
            tmp->level++;
        tmp->in_incantation = false;
        if (tmp->level == MAX_LEVEL)
            tmp->team->max_lvl_players++;
    }
}

/// \brief Send ko message to players who failed an incantation
/// \param tile_players
/// \param cur_level
void send_ko_to_ritual_players(player_t *tile_players, int cur_level)
{
    for (player_t *tmp = tile_players; tmp; tmp = tmp->next_neighbor) {
        if (tmp->client && tmp->level == cur_level)
            add_to_buffer("ko\n", &tmp->client->base.buffer_out);
        tmp->in_incantation = false;
    }
}

/// \brief Allow player to incant
/// \param cmd
/// \param player
/// \param game
/// \return status
int cmd_incantation(char *cmd, player_t *player, game_t *game)
{
    int player_lvl = player->level;

    UNUSED(cmd);
    UNUSED(game);
    if (player_lvl <= EGG || player_lvl >= MAX_LEVEL) {
        send_ko_to_ritual_players(player->tile->players, player_lvl);
        incantation_end_log(&player->tile->pos, false, &game->game_log);
        return (RESP_OTHER);
    }
    if (!check_if_ritual_req_met(&ritual_data[player_lvl - 1], player)) {
        send_ko_to_ritual_players(player->tile->players, player_lvl);
        incantation_end_log(&player->tile->pos, false, &game->game_log);
        return (RESP_OTHER);
    }
    remove_resources_from_tile(&ritual_data[player_lvl - 1].inv, player->tile);
    take_log_inventory(&ritual_data[player_lvl - 1].inv, player->id, \
&game->game_log);
    upgrade_ritual_players(player->tile->players, player_lvl);
    incantation_end_log(&player->tile->pos, true, &game->game_log);
    return (RESP_OTHER);
}
