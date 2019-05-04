/*
** EPITECH PROJECT, 2019
** display_info.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int display_info(game_t *game)
{
    game_object_t *obj = game->scenes->objs->game_object;

    while (obj->prev != NULL)
        obj = obj->prev;
    for (int i = 0; i <2; i++)
        obj = obj->next;
    if (obj->display == true)
        obj->display = false;
    else
        obj->display = true;
    return (0);
}
