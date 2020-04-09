/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "network/client.h"

void reset_client_timer(client_t *client)
{
    client->base.timeout = INACTIVE_TIMEOUT;
}