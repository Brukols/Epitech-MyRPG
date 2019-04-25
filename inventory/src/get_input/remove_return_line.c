/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** remove_return_line
*/

#include "inventory.h"

char *remove_return_line(char *buffer)
{
    int pos = 0;

    if (buffer == NULL)
        return (NULL);
    while (buffer[pos] != '\n' && buffer[pos] != '\0')
        pos++;
    if (buffer[pos] == '\n')
        buffer[pos] = '\0';
    return (buffer);
}
