/*
** EPITECH PROJECT, 2019
** dislay_buttons_menu
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool mouse_is_hover(buttons_t *button, game_t *game)
{
    sfVector2i mouse_tmp = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse = init_vec2f(mouse_tmp.x, mouse_tmp.y);

    if (click(button->hitbox_pos, button->size, mouse) == false)
        return (false);
    if (button->type == START) {
        button->rect.left = 0;
        sfSprite_setTextureRect(button->sprite, button->rect);
    }
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->hover, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    return (true);
}

void display_button_play(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons->type != START; buttons = buttons->next);
    if (mouse_is_hover(buttons, game) == true)
        return;
    if (sfClock_getElapsedTime(buttons->clock).microseconds > 600000) {
        buttons->rect.left = (buttons->rect.left == 0 ? 480 : 0);
        sfClock_restart(buttons->clock);
    }
    sfSprite_setTextureRect(buttons->sprite, buttons->rect);
    sfSprite_setPosition(buttons->sprite, buttons->pos);
    sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
}

void display_other_buttons_menu(game_t *game)
{
    buttons_t *buttons = game->scenes->buttons;

    for (; buttons; buttons = buttons->next) {
        if (buttons->type == START)
            continue;
        if (mouse_is_hover(buttons, game) == true)
            continue;
        sfSprite_setPosition(buttons->sprite, buttons->pos);
        sfSprite_setTexture(buttons->sprite, buttons->texture, sfFalse);
        sfRenderWindow_drawSprite(game->window, buttons->sprite, NULL);
    }
}

void display_buttons_menu(game_t *game)
{
    display_button_play(game);
    display_other_buttons_menu(game);
}