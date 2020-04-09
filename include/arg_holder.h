/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#ifndef ARG_HOLDER_H_
#define ARG_HOLDER_H_

typedef struct s_arg_holder
{
    unsigned int port;
    unsigned int width;
    unsigned int height;
    char **names;
    unsigned int clients_nbr;
    float freq;
} arg_holder_t;

arg_holder_t *get_args(int ac, char **av);
void free_arg_holder(arg_holder_t *arg_hldr);
void print_arg_holder(arg_holder_t *arg_hldr);
int handle_opt_p(char **arg, arg_holder_t *arg_holder, int *i);
int handle_opt_x(char **arg, arg_holder_t *arg_holder, int *i);
int handle_opt_y(char **arg, arg_holder_t *arg_holder, int *i);
int handle_opt_c(char **arg, arg_holder_t *arg_holder, int *i);
int handle_opt_f(char **arg, arg_holder_t *arg_holder, int *i);
int handle_opt_n(char **arg, arg_holder_t *arg_holder, int *i);

#endif