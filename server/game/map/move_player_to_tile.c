/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/player.h"

/// \brief Move the given player to the new tile
/// \param player
/// \param tile
/// \return true or false, depending on success
bool move_player_to_tile(player_t *player, tile_t *tile)
{
    tile_t *cur_tile = player->tile;

    if (!cur_tile)
        return (false);
    if (!remove_player_from_tile(player, cur_tile))
        return (false);
    if (!append_to_tile_player_list(tile, player))
        return (false);
    player->tile = tile;
    return (true);
}

/// \brief Move the given player to the next tile in the given direction
/// \param player
/// \param dir
/// \return true or false, depending on success
bool move_player_in_dir(player_t *player, dir_t dir)
{
    tile_t *tile = get_tile_in_dir(player->tile, dir);

    if (!tile)
        return (false);
    if (tile == player->tile)
        return (true);
    return (move_player_to_tile(player, tile));
}