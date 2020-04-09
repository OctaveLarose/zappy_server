/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by thomas
*/

#include "errors.h"
#include "macros.h"
#include "arg_holder.h"

int error_print(const char *msg)
{
    fputs(msg, stderr);
    return (ERR);
}

void *error_print_ptr(const char *msg)
{
    fputs(msg, stderr);
    return (NULL);
}