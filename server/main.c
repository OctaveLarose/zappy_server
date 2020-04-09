/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "zappy.h"
#include "game/map.h"

/// \brief Main game function, firstly init everything then launch the game
///        and take care of freeing the memory after
/// \param args
/// \return ERR or OK
int zappy(arg_holder_t *args)
{
    zappy_t zappy;
    int ret;

    if (init_zappy(&zappy, args) == ERR)
        return (ERR);
    free_arg_holder(args);
    ret = run_zappy(&zappy);
    puts("The game is over.");
    free_zappy(&zappy);
    return (ret == GAME_WIN ? OK : ERR);
}

int main(int ac, char **av)
{
    arg_holder_t *arg_hldr;
    int ret;

    if (ac >= 2 && strcmp(av[1], "-help") == 0) {
        usage(av[0]);
        return (OK);
    }
    srand(clock());
    do {
        arg_hldr = get_args(ac, av);
        if (!arg_hldr)
            return (ERR);
        ret = zappy(arg_hldr);
    } while (ZAPPY_RESET_AFTER_OVER);
    return (ret);
}