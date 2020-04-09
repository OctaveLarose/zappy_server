/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "errors.h"
#include "macros.h"

int error(const char *func)
{
    perror(func);
    return (ERR);
}

int error_close(const char *func, int fd)
{
    if (fd)
        close(fd);
    perror(func);
    return (ERR);
}