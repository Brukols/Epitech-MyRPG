/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** int_box_dialog
*/

#include "my_rpg.h"

int nothing(__attribute__((unused)) game_t *game)
{
    return (SUCCESS);
}

buttons_t *init_box_dialog(buttons_t *button)
{
    if (!(button->texture = sfTexture_createFromFile(\
        "ressources/sprites/box_dialog2.png", NULL)))
        return (NULL);
    if (!(button->sprite = sfSprite_create()))
        return (NULL);
    button->type = BOX_DIALOG;
    button->display = true;
    button->pos = init_vec2f(380, 700);
    button->size = init_vec2f(1136, 300);
    button->rect = init_intrect(0, 0, 1136, 300);
    button->hitbox_pos = init_vec2f(380, 700);
    button->callback = &nothing;
    button->next = NULL;
    return (button);
}