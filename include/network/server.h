/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdbool.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "client.h"
#include "server_macros.h"

typedef struct s_zappy zappy_t;

#define LISTEN_MAX_CLIENT 255
#define SELECT_WAIT_USEC 2000

typedef struct s_server {
    int socket;
    struct sockaddr_in sockaddr;
    int port;
    client_t *clients;
    fd_set perm_rfds;
    fd_set tmp_rfds;
    fd_set wfds;
    struct timeval select_timeout;
} server_t;

int init_server(server_t *server, int port);
bool select_server(zappy_t *zappy, fd_set *rfds, fd_set *wfds);
void set_wfds(server_t *server, char *game_log);
int manage_rfds(client_t **client, zappy_t *server);
int manage_wfds(client_t **client, zappy_t *server);
int handle_client_ai_wfds(client_t **client, zappy_t *zappy);
int handle_client_graph_wfds(client_t **client, zappy_t *zappy);
bool handle_new_connection(zappy_t *zappy);
bool respond_to_client(client_t *client);
bool send_init_info_to_graph(client_graphic_t *client, game_t *game);
int add_to_init_graph_response(char *str, client_graphic_t *client);
bool send_info_to_graphical(client_graphic_t *client, char *game_log);
int recv_client_info(client_t *client);
bool handle_client(client_t **client, zappy_t *zappy);
int give_player_to_client(client_ai_t *client, game_t *game, char *team_name);
void disconnect_client(client_t **, server_t *, const char *reason);
bool parse_command(c_buffer_t *, char commands[MAX_COMMANDS][MAX_CMD_LEN]);

#endif