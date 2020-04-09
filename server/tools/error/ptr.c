/*
** EPITECH PROJECT, 2019
** errors.c
** File description:
** errors tools
*/

#include "errors.h"
#include "macros.h"

void *error_ptr(const char *func)
{
    perror(func);
    return (NULL);
}

void *error_close_ptr(const char *func, int fd)
{
    if (fd)
        close(fd);
    perror(func);
    return (NULL);
}