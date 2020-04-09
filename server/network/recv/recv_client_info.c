/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/server.h"

int recv_client_info(client_t *client)
{
    char buf[MAX_CMD_LEN];
    ssize_t len_recv;
    client_base_t *base = (client_base_t*)client;

    len_recv = recv(base->socket, buf, MAX_CMD_LEN, 0);
    buf[len_recv] = 0;
    add_to_buffer(buf, &client->base.buffer_in);
    return (len_recv);
}