/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/game.h"
#include "game/player.h"
#include "game/log.h"

/// \brief Give a tile to the given player, could be random or via a position
/// \param player
/// \param world
/// \param random_pos
/// \param pos
/// \return true or false, depending on success
bool init_player_tile(player_t *player, world_t *world, bool random_pos, \
vec2i_t *pos)
{
    if (random_pos)
        player->tile = get_random_tile(world);
    else
        player->tile = get_tile(world, pos);
    if (!player->tile) {
        free_player(player);
        return (false);
    }
    return (true);
}

/// \brief Allocate and fill a player structure with given info
/// \param info
/// \param world
/// \param f
/// \return a pointer to allocated player
player_t *create_player(player_info_t info, world_t *world, double f)
{
    player_t *player = calloc(1, sizeof(player_t));
    static int id = 0;

    if (!player)
        return (NULL);
    player->id = id++;
    player->team = info.team;
    player->level = info.is_egg ? EGG : 1;
    player->action_time_left = info.is_egg ? 600 / f * SECOND_NBR : 0;
    player->client = info.client;
    player->direction = rand() % 4;
    player->in_incantation = false;
    player->inventory.food = START_FOOD;
    player->ttl = (TIME_UNITS_PER_FOOD * START_FOOD / f) * SECOND_NBR;
    if (!init_player_tile(player, world, info.random_pos, &info.pos))
        return (NULL);
    return (player);
}

/// \brief Allocate, fill and add a player to the world
/// \param game
/// \param info
/// \return a pointer to the player
player_t *make_new_player(game_t *game, player_info_t info)
{
    player_t *player = create_player(info, &game->world, game->freq);

    if (!player)
        return (NULL);
    spawn_player_log(player, &game->game_log);
    append_to_global_player_list(&game->players, player);
    append_to_team_player_list(info.team, player);
    append_to_tile_player_list(player->tile, player);
    return (player);
}