/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "arg_holder.h"
#include "zappy.h"

int handle_opt_p(char **arg, arg_holder_t *arg_holder, int *i)
{
    char *endptr;
    long res;

    (*i)++;
    res = strtol(arg[1], &endptr, 10);
    if (endptr == arg[1] || *endptr != '\0') {
        fprintf(stderr, "Invalid %s argument : %s\n", arg[0], arg[1]);
        return (ERR);
    }
    if (res <= 0) {
        fprintf(stderr, "Port number should be superior to 0.\n");
        return (ERR);
    }
    arg_holder->port = (unsigned int)res;
    return (OK);
}

int handle_opt_x(char **arg, arg_holder_t *arg_holder, int *i)
{
    char *endptr;
    long res;

    (*i)++;
    res = strtol(arg[1], &endptr, 10);
    if (endptr == arg[1] || *endptr != '\0') {
        fprintf(stderr, "Invalid %s argument : %s\n", arg[0], arg[1]);
        return (ERR);
    }
    if (res <= 0) {
        fprintf(stderr, "Width should be superior to 0.\n");
        return (ERR);
    }
    arg_holder->width = (unsigned int)res;
    return (OK);
}

int handle_opt_y(char **arg, arg_holder_t *arg_holder, int *i)
{
    char *endptr;
    long res;

    (*i)++;
    res = strtol(arg[1], &endptr, 10);
    if (endptr == arg[1] || *endptr != '\0') {
        fprintf(stderr, "Invalid %s argument : %s\n", arg[0], arg[1]);
        return (ERR);
    }
    if (res <= 0) {
        fprintf(stderr, "Height should be superior to 0.\n");
        return (ERR);
    }
    arg_holder->height = (unsigned int)res;
    return (OK);
}

int handle_opt_c(char **arg, arg_holder_t *arg_holder, int *i)
{
    char *endptr;
    long res;

    (*i)++;
    res = strtol(arg[1], &endptr, 10);
    if (endptr == arg[1] || *endptr != '\0') {
        fprintf(stderr, "Invalid %s argument : %s\n", arg[0], arg[1]);
        return (ERR);
    }
    if (res <= 0) {
        fprintf(stderr, "Clients number should be superior to 0.\n");
        return (ERR);
    }
    arg_holder->clients_nbr = (unsigned int)res;
    return (OK);
}

int handle_opt_f(char **arg, arg_holder_t *arg_holder, int *i)
{
    char *endptr;
    double res;

    (*i)++;
    res = strtof(arg[1], &endptr);
    if (endptr == arg[1] || *endptr != '\0') {
        fprintf(stderr, "Invalid %s argument : %s\n", arg[0], arg[1]);
        return (ERR);
    }
    if (res <= 0) {
        fprintf(stderr, "Frequency should be superior to 0.\n");
        return (ERR);
    }
    arg_holder->freq = res;
    return (OK);
}