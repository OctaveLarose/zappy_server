/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"

/// \brief Push the given player to the given linked list
/// \param first
/// \param player
/// \return true or false, depending on success
bool append_to_global_player_list(player_t **first, player_t *player)
{
    player_t *last;

    if (first == NULL)
        return (false);
    last = get_last_global_player(*first);
    if (last == NULL)
        *first = player;
    else
        last->next_player = player;
    player->next_player = NULL;
    return (true);
}