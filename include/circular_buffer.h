/*
** EPITECH PROJECT, 2022
** Project
** File description:
** Created by olarose
*/

#ifndef CIRCULAR_BUFFER_H_
#define CIRCULAR_BUFFER_H_

#define CIRCULAR_BUFFER_LEN 4096

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct s_circular_buffer {
    char buffer[CIRCULAR_BUFFER_LEN];
    int read_offset;
    int write_offset;
    int nbr_bytes;
} c_buffer_t;

#define ADD_FAIL (-1)

void init_c_buffer(c_buffer_t *buffer);
int add_to_buffer(char *str, c_buffer_t *buffer);
char *read_from_buffer(c_buffer_t *buffer);
bool is_buf_readable(c_buffer_t *buffer);
bool has_command(c_buffer_t *buffer);
void print_buffer_content(c_buffer_t *buffer);

#endif