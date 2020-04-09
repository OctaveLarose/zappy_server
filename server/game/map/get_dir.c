/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/map.h"

/// \brief Get the relative left direction from a given one
/// \param dir
/// \return a direction
dir_t get_dir_to_left(dir_t dir)
{
    dir_t new_dir;

    if (dir < 0 || dir > 3)
        return (INVALID_DIR);
    new_dir = dir - 1;
    if (new_dir < 0)
        new_dir = 3;
    return (new_dir);
}

/// \brief Get the relative right direction from a given
/// \param dir
/// \return a direction
dir_t get_dir_to_right(dir_t dir)
{
    dir_t new_dir;

    if (dir < 0 || dir > 3)
        return (INVALID_DIR);
    new_dir = dir + 1;
    if (new_dir > 3)
        new_dir = 0;
    return (new_dir);
}