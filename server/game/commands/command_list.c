/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#include "game/commands.h"

const struct s_command command_list[] = {
    {.name = "Forward", .cmd_ptr = &cmd_forward, 7},
    {.name = "Right", .cmd_ptr = &cmd_right, 7},
    {.name = "Left", .cmd_ptr = &cmd_left, 7},
    {.name = "Look", .cmd_ptr = &cmd_look, 7},
    {.name = "Inventory", .cmd_ptr = &cmd_inventory, 1},
    {.name = "Broadcast", .cmd_ptr = &cmd_broadcast, 7},
    {.name = "Connect_nbr", .cmd_ptr = &cmd_connect_nbr, 0},
    {.name = "Fork", .cmd_ptr = &cmd_fork, 42},
    {.name = "Eject", .cmd_ptr = &cmd_eject, 7},
    {.name = "Take", .cmd_ptr = &cmd_take, 7},
    {.name = "Set", .cmd_ptr = &cmd_set, 7},
    {.name = "Incantation", .cmd_ptr = &cmd_incantation, 300},
    {.name = NULL}
};