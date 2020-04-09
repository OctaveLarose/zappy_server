/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "arg_holder.h"
#include "zappy.h"

void free_arg_holder(arg_holder_t *arg_hldr)
{
    free(arg_hldr->names);
    free(arg_hldr);
}

/// \brief Check if all flags are filled
/// \param arg_hldr
/// \return a status
int check_arg_holder(arg_holder_t *arg_hldr)
{
    int n = 0;

    if (arg_hldr->height == 0)
        printf("Height not specified.%n\n", &n);
    if (arg_hldr->width == 0)
        printf("Width not specified.%n\n", &n);
    if (arg_hldr->clients_nbr == 0)
        printf("Clients number not specified.%n\n", &n);
    if (arg_hldr->port == 0)
        printf("Port number not specified.%n\n", &n);
    if (arg_hldr->names[0] == NULL)
        printf("Team names not specified.%n\n", &n);
    return (n == 0 ? OK : ERR);
}

/// \brief Loop through all cli args and redirect the value to the
///        corresponding function
/// \param ac
/// \param av
/// \param arg_hldr
/// \return
int get_args_loop(int ac, char **av, arg_holder_t *arg_hldr)
{
    char *flags_list = "pxycfn";
    char *idx_flag;
    int (*func_arr[])(char **, arg_holder_t *, int *) = {&handle_opt_p, \
&handle_opt_x, &handle_opt_y, &handle_opt_c, &handle_opt_f, &handle_opt_n};

    for (int i = 1; i < ac; i++) {
        if (strlen(av[i]) != 2 || av[i][0] != '-') {
            fprintf(stderr, "Invalid argument : %s\n", av[i]);
            return (ERR);
        }
        idx_flag = strchr(flags_list, av[i][1]);
        if (!idx_flag) {
            fprintf(stderr, "Invalid option : %s\n", av[i]);
            return (ERR);
        }
        if (func_arr[idx_flag - flags_list](&av[i], arg_hldr, &i) == ERR)
            return (ERR);
    }
    return (OK);
}

/// \brief Read args from the command line
/// \param ac
/// \param av
/// \return
arg_holder_t *get_args(int ac, char **av)
{
    arg_holder_t *arg_hldr = calloc(1, sizeof(arg_holder_t));

    if (!arg_hldr)
        return (error_ptr("malloc"));
    arg_hldr->freq = DEFAULT_FREQ;
    arg_hldr->names = calloc(ac, sizeof(char *));
    if (!arg_hldr->names) {
        free(arg_hldr);
        return (error_ptr("malloc"));
    }
    if (get_args_loop(ac, av, arg_hldr) == ERR) {
        free_arg_holder(arg_hldr);
        return (NULL);
    }
    if (check_arg_holder(arg_hldr) == ERR) {
        free_arg_holder(arg_hldr);
        return (NULL);
    }
    return (arg_hldr);
}