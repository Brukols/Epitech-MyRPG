/*
** EPITECH PROJECT, 2019
** my_rog
** File description:
** init_buttons_fs_scene
*/

#include "my_rpg.h"

buttons_t *init_buttons_fs_scene(void)
{
    buttons_t *buttons = malloc(sizeof(buttons_t));

    if (!buttons)
        return (NULL);
    buttons->prev = NULL;
    if (!(buttons = init_box_dialog(buttons)))
        return (NULL);
    buttons->next = NULL;
    return (buttons);
}