/*
** EPITECH PROJECT, 2018
** PSU_zappy_2018
** File description:
** Get clients
*/

#include "network/client.h"

/// \brief Find a client corresponding to the given file descriptor in a given
///        client linked list
/// \param first
/// \param fd
/// \return a pointer to the found client
client_t *get_client_by_fd(client_t *first, int fd)
{
    while (first != NULL && first->base.socket != fd)
        first = first->base.next;
    return (first);
}

/// \brief Find the last item in a given client linked list
/// \param first
/// \return a pointer to the last client, NULL in case of error
client_t *get_last_client(client_t *first)
{
    if (first == NULL)
        return (NULL);
    while (first->base.next != NULL)
        first = first->base.next;
    return (first);
}