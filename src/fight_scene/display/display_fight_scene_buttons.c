/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_fight_scene_buttons
*/

#include "my_rpg.h"

void display_fight_scene_buttons(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    //for (; buttons->prev; buttons = buttons->prev);
    while (button->prev != NULL)
        button = button->prev;
    //for (; buttons; buttons = buttons->next) {
    while (button != NULL) {
        if (button->display == true)
            sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
        button = button->next;
    }
}
