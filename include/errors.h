/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef ERRORS_H_
#define ERRORS_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int error(const char *func);
int error_close(const char *func, int fd);
int error_print(const char *msg);

void *error_ptr(const char *func);
void *error_close_ptr(const char *func, int fd);
void *error_print_ptr(const char *msg);

#endif