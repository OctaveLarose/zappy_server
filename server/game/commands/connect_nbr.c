/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/


#include "game/commands.h"
#include "macros.h"

/// \brief Return the number of unused players in the game
/// \param cmd
/// \param player
/// \param game
/// \return 
int cmd_connect_nbr(char *cmd, player_t *player, game_t *game)
{
    char buffer[16];
    int clients_num;

    UNUSED(cmd);
    UNUSED(game);
    if (!player->team)
        return (RESP_KO);
    clients_num = player->team->clients_num;
    clients_num += get_team_nbr_players_free(player->team);
    clients_num -= get_team_nbr_players_not_free(player->team);
    sprintf(buffer, "%d\n", clients_num);
    add_to_buffer(buffer, &player->client->base.buffer_out);
    return (RESP_OTHER);
}
