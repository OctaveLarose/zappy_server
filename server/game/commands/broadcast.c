/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/


#include "game/commands.h"
#include "macros.h"
#include <math.h>

/// \brief Convert an angle in degree to the possible tile output
/// \param angle
/// \return 0 to 8
int convert_angle_to_num(double angle)
{
    if ((angle > 315 && angle <= 360) || (angle >= 0 && angle < 45))
        return (1);
    if (angle == 45)
        return (8);
    if (angle > 45 && angle < 135)
        return (7);
    if (angle == 135)
        return (6);
    if (angle > 135 && angle < 205)
        return (5);
    if (angle == 205)
        return (4);
    if (angle > 205 && angle < 315)
        return (3);
    if (angle == 315)
        return (2);
    return (0);
}

/// \brief Get an angle from two vectors
/// \param target
/// \param origin
/// \return actual angle in degree
double get_angle(vec2i_t target, vec2i_t origin)
{
    double res = (((target.x * origin.x) + (target.y * origin.y)) \
/ (sqrt((target.x * target.x) + (target.y * target.y)) \
* sqrt((origin.x * origin.x) + (origin.y * origin.y))));

    res = acos(res);
    res = res * (180.0 / M_PI);
    return (res);
}

/// \brief Create a vector from a position and a direction
/// \param dir
/// \param src
/// \return the vector
vec2i_t get_origin(dir_t dir, vec2i_t *src)
{
    switch (dir) {
    case NORTH:
        return ((vec2i_t){0, (src->y - 1) - src->y});
    case EAST:
        return ((vec2i_t){(src->x + 1) - src->x, 0});
    case SOUTH:
        return ((vec2i_t){0, (src->y + 1) - src->y});
    case WEST:
        return ((vec2i_t){(src->x - 1) - src->x, 0});
    default:
        return ((vec2i_t){0, (src->y - 1) - src->y});
    }
}

char get_traj(player_t *source_player, player_t *dest_player, world_t *world)
{
    vec2i_t *src = &source_player->tile->pos;
    vec2i_t target = {dest_player->tile->pos.x - src->x, \
dest_player->tile->pos.y - src->y};
    double res = get_angle(*src, get_origin(dest_player->direction, &target));

    UNUSED(world);
    if (src->x == dest_player->tile->pos.x && \
src->y == dest_player->tile->pos.y)
        return (0);
    return (convert_angle_to_num(res));
}

/// \brief Send a message to all player, with the direction the message is
///        coming from
/// \param cmd
/// \param player
/// \param game
/// \return status of execution
int cmd_broadcast(char *cmd, player_t *player, game_t *game)
{
    char buffer[12];
    char *arg = cmd;

    UNUSED(game);
    while (*arg && *arg != ' ')
        arg++;
    if (*arg == '\0')
        return (RESP_KO);
    for (player_t *tmp = game->players; tmp; tmp = tmp->next_player) {
        if (!tmp->client || tmp == player)
            continue;
        sprintf(buffer, "message %d,", get_traj(player, tmp, &game->world));
        add_to_buffer(buffer, &tmp->client->base.buffer_out);
        add_to_buffer(arg, &tmp->client->base.buffer_out);
        add_to_buffer("\n", &tmp->client->base.buffer_out);
    }
    return (RESP_OK);
}