/*
** EPITECH PROJECT, 2019
** setting + exit buttons
** File description:
** my rpg
*/

#include "my_rpg.h"

void idle_exit_button(game_t *game, char *str)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != MENU_EXIT; button = button->next);
    button->texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}

void idle_settings_button(game_t *game, char *str)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != MENU_SETTINGS; button = button->next);
    button->texture = sfTexture_createFromFile(str, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
}

void idle_bottoms_buttons(sfVector2i mouse_pos, game_t *game)
{
    if (mouse_pos.x >= 1820 && mouse_pos.x <= 1920 &&    \
        mouse_pos.y >= 900 && mouse_pos.y <= 1000)
        idle_settings_button(game,                      \
        "../../ressources/sprites/menu/exit2.png");
    else if (mouse_pos.x >= 1700 && mouse_pos.x <= 1800 &&     \
        mouse_pos.y >= 900 && mouse_pos.y <= 1000)
        idle_exit_button(game,                          \
        "../../ressources/sprites/menu/settings2.png");
    else {
        idle_exit_button(game,                          \
        "../../ressources/sprites/menu/settings.png");
        idle_settings_button(game,                      \
        "../../ressources/sprites/menu/exit.png");
    }
}
