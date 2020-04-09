/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "zappy.h"

/// \brief Go over all players and check if some don't have a client connected
///        on
/// \param pls
/// \param team
/// \param cli
/// \return
player_t *check_for_free_player(player_t *pls, team_t *team, client_ai_t *cli)
{
    for (player_t *tmp = pls; tmp; tmp = tmp->next_player)
        if (!tmp->client && tmp->team == team && tmp->level != EGG && \
tmp->ttl > 0) {
            tmp->client = cli;
            return (tmp);
        }
    return (NULL);
}

/// \brief Attribute a player to a client, if none available, it will create
///        a new one
/// \param client
/// \param game
/// \param team_name
/// \return status
int give_player_to_client(client_ai_t *client, game_t *game, char *team_name)
{
    team_t *team = get_team(game->teams, team_name);
    player_t *player;
    player_info_t info;

    if (!team)
        return (INVALID_TEAM);
    player = check_for_free_player(game->players, team, client);
    if (player) {
        client->player = player;
        return (OK);
    }
    if (get_team_nbr_players(team) >= team->clients_num)
        return (TEAM_OUT_OF_SPACE);
    info = (player_info_t) {false, true, {}, team, client};
    player = make_new_player(game, info);
    if (!player)
        return (UNEXPECTED_SERVER_ERROR);
    client->player = player;
    return (OK);
}