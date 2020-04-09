/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "arg_holder.h"
#include "zappy.h"

bool is_arg_option(char *str)
{
    return (strlen(str) == 2 && str[0] == '-');
}

int handle_opt_n(char **arg, arg_holder_t *arg_holder, int *i)
{
    int name_idx = 0;

    for (int j = 1; arg[j] != 0 && !is_arg_option(arg[j]); j++)
        arg_holder->names[name_idx++] = arg[j];
    if (name_idx == 0) {
        fprintf(stderr, "No argument given to %s.\n", arg[0]);
        return (ERR);
    }
    (*i) += name_idx;
    return (OK);
}