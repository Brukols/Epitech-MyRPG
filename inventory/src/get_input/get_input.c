/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** get_input
*/

#include "inventory.h"

char *get_input(void)
{
    char *buffer = NULL;
    size_t len = 0;

    if (getline(&buffer, &len, stdin) < 0)
        return (NULL);
    buffer = remove_return_line(buffer);
    return (buffer);
}
