/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "game/log.h"
#include "macros.h"

bool handle_player_command(player_t *player, game_t *game)
{
    int ret;

    if (player->level == EGG) {
        player->level = 1;
        hatch_log(player, &game->game_log);
        return (true);
    }
    if (player->client && player->cur_action) {
        ret = execute_player_command(player->cur_action, player, game);
        player->cur_action = NULL;
        return (fill_response_to_client(&player->client->base.buffer_out, ret));
    }
    return (true);
}

/// \brief Execute pending commands on players
/// \param players
/// \param game
/// \return
bool handle_players(player_t *players, game_t *game)
{
    player_t *tmp = players;

    while (tmp != NULL) {
        if (tmp->action_time_left <= 0)
            handle_player_command(tmp, game);
        if (!tmp->cur_action && !tmp->in_incantation && \
has_pending_commands(tmp))
            set_player_command(tmp, game->freq, &game->game_log);
        tmp = tmp->next_player;
    }
    return (true);
}

bool should_game_reset(game_t *game)
{
    static bool at_least_one_player_lived = false;
    int nbr_players = get_nbr_players_global(game->players);

    if (at_least_one_player_lived && nbr_players == 0) {
        at_least_one_player_lived = false;
        return (true);
    } else if (nbr_players != 0)
        at_least_one_player_lived = true;
    return (false);
}

/// \brief Update the game state
/// \param game
/// \return
int update_game(game_t *game)
{
    if (clock() % RESOURCE_SPAWN_RATE == 0)
        spawn_resource(&game->world, &game->game_log);
    handle_players(game->players, game);
    if (ZAPPY_END_GAME_WHEN_PLAYERS_DEAD)
        if (should_game_reset(game))
            return (GAME_WIN);
    if (check_if_game_won(game->teams))
        return (GAME_WIN);
    return (OK);
}