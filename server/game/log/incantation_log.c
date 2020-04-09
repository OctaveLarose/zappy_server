/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/log.h"

/// \brief Send a notification that an incantation has started to the graphic
/// \param pos
/// \param game_log
/// \return
int incantation_start_log(vec2i_t *pos, buffer_t *game_log)
{
    char log_msg[30];

    sprintf(log_msg, "inc %d %d\n", pos->x, pos->y);
    return (add_str_to_buffer(log_msg, game_log));
}

/// \brief Send a notification that an incantation ended to the graphic
/// \param pos
/// \param res
/// \param game_log
/// \return
int incantation_end_log(vec2i_t *pos, bool res, buffer_t *game_log)
{
    char log_msg[30];

    sprintf(log_msg, "end %d %d %s\n", pos->x, pos->y, res ? "OK" : "KO");
    return (add_str_to_buffer(log_msg, game_log));
}