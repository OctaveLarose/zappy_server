/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/


#include "game/player.h"

/// \brief Remove the given player from the given linked list
/// \param player
/// \param list
/// \return true if removed, false otherwise
bool remove_player_from_global_player_list(player_t *player, player_t **list)
{
    player_t *prev = NULL;
    player_t *idx = *list;
    player_t *next = NULL;

    if (idx != NULL && idx == player) {
        *list = (*list)->next_player;
        return (true);
    }
    while (idx != NULL && idx != player) {
        prev = idx;
        idx = idx->next_player;
        next = idx->next_player;
    }
    if (idx == NULL)
        return (false);
    prev->next_player = next;
    return (true);
}

/// \brief Free the memory allocated for the given player
/// \param player
void free_player(player_t *player)
{
    if (player->client) {
        player->client->player = NULL;
        player->client = NULL;
    }
    free(player);
}

/// \brief Delete a player from the game (remove and free), send him a "dead"
/// \param player
/// \param global_list
void free_all_players(player_t *player)
{
    player_t *tmp = player;
    player_t *next;

    while (tmp) {
        next = tmp->next_player;
        free_player(tmp);
        tmp = next;
    }
}

/// \brief Remove a player from its tile and team and remove it from global
///        player linked list
/// \param player
/// \param global_list
void remove_player(player_t **player, player_t **global_list)
{
    if ((*player)->team)
        remove_player_from_tile(*player, (*player)->tile);
    if ((*player)->team)
        remove_player_from_team(*player, (*player)->team);
    remove_player_from_global_player_list(*player, global_list);
}

/// \brief Call remove player, send a message about its death to clients
///        then free the memory allocated for it
/// \param player
/// \param global_list
void delete_player(player_t **player, player_t **global_list)
{
    player_t *next = (*player)->next_player;

    remove_player(player, global_list);
    if ((*player)->client) {
        memset(&(*player)->client->base.buffer_out, 0, MAX_CMD_LEN);
        add_to_buffer("dead\n", &(*player)->client->base.buffer_out);
        (*player)->client->has_player = false;
    }
    free_player(*player);
    *player = next;
}