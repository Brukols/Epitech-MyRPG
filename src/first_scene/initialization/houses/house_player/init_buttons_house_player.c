/*
** EPITECH PROJECT, 2019
** init_button_house_player
** File description:
** my_rpg
*/

#include "my_rpg.h"

buttons_t *init_buttons_house_player(void)
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