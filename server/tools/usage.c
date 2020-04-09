/*
** EPITECH PROJECT, 2022
** PSU_zappy_2018
** File description:
** Created by olarose
*/

#include "zappy.h"

void usage(char *bin_name)
{
    printf("USAGE: %s -p port -x width -y height ", bin_name);
    puts("-n name1 name2 ...  -c clientsNb -f freq");
    puts("\tport\t\tis the port number");
    puts("\twidth\t\tis the width of the world");
    puts("\theight\t\tis the height of the world");
    puts("\tnameX\t\tis the name of the team X");
    puts("\tclientsNb\tis the number of authorized clients per team");
    puts("\tfreq\t\tis the reciprocal of time unit for execution of actions");
}