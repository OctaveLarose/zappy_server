/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by bgenestal,
*/

#include "zappy.h"

unsigned int get_array_size(char **array)
{
    int i = 0;

    if (array == NULL)
        return (0);
    for (i = 0; array[i] != NULL; i++);
    return (i);
}