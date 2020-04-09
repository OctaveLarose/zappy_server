/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <game/player.h>
#include "circular_buffer.h"

typedef struct s_player player_t;
typedef struct s_server server_t;

typedef enum client_type {
    CLIENT_AI,
    CLIENT_GRAPHIC,
    CLIENT_UNKNOWN
} client_type_t;

typedef enum client_status {
    WAITING_WELCOME,
    WAITING_CLIENT_INFO,
    WAITING_SERV_INFO,
    READY
} client_status_t;

#define MAX_COMMANDS 10
#define MAX_CMD_LEN (CIRCULAR_BUFFER_LEN)

#define NOT_DONE 42

#define SECONDS_BEFORE_TIMEOUT 100
#define INACTIVE_TIMEOUT (SECONDS_BEFORE_TIMEOUT * CLOCKS_PER_SEC / 100)

typedef union client_union client_t;

typedef struct s_client_base {
    client_type_t type;
    client_status_t status;
    clock_t timeout;
    int socket;
    char commands[MAX_COMMANDS][MAX_CMD_LEN];
    c_buffer_t buffer_in;
    c_buffer_t buffer_out;
    client_t *next;
} client_base_t;

typedef struct s_client_ai {
    client_base_t base;
    player_t *player;
    bool has_player;
} client_ai_t;

typedef struct s_client_graphic {
    client_base_t base;
} client_graphic_t;

typedef union client_union {
    client_base_t base;
    client_ai_t ai;
    client_graphic_t graphic;
} client_t;

client_t *accept_client(server_t *server);

client_t *create_client(int socket);

bool append_to_client_list(client_t **first, client_t *client);

client_t *get_client_by_fd(client_t *first, int fd);

client_t *get_last_client(client_t *first);

void delete_client(client_t **first, int fd);

void free_client(client_t *client);

void free_all_clients(client_t *client);

void reset_client_timer(client_t *client);

bool remove_endline_from_command(char *str);

#endif