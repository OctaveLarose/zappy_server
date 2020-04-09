/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Tell the graphic a new player arrived
/// \param player
/// \param game_log
/// \return
bool spawn_player_log(player_t *player, buffer_t *game_log)
{
    char str[80];
    vec2i_t *pos;
    char type = player->level == EGG ? 'E' : 'P';

    if (!player->tile)
        return (false);
    pos = &player->tile->pos;
    sprintf(str, "spw %d %d %c %d %d ", pos->x, pos->y, type, player->id, \
player->direction);
    add_str_to_buffer(str, game_log);
    if (player->team)
        add_str_to_buffer(player->team->name, game_log);
    else
        add_str_to_buffer("NO_TEAM", game_log);
    add_str_to_buffer("\n", game_log);
    return (true);
}

/// \brief Tell the graphic a new resource spawned
/// \param pos
/// \param resource
/// \param game_log
/// \return
bool spawn_resource_log(vec2i_t *pos, resource_t resource, buffer_t *game_log)
{
    char str[50];

    sprintf(str, "spw %d %d %d\n", pos->x, pos->y, resource);
    return (add_str_to_buffer(str, game_log));
}