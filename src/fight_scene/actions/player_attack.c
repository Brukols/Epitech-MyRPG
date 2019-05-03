/*
** EPITECH PROJECT, 2019
** player_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int player_attack(scenes_t *scene)
{
    buttons_t *buttons = scene->buttons;

    while (buttons->prev != NULL)
        buttons = buttons->prev;
    for (int i = 0; i < 3; i++)
        buttons = buttons->next;
    while (buttons != NULL) {
        if (buttons->display == true) {
            buttons->display = false;
        } else {
            buttons->display = true;
        }
        buttons = buttons->next;
    }
    return (0);
}
