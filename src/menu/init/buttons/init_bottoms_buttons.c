/*
** EPITECH PROJECT, 2019
** init bottoms (exit + setting buttons)
** File description:
** my rpg
*/

#include "my_rpg.h"

int leave_the_game(game_t *game)
{
    sfRenderWindow_close(game->window);
    return (SUCCESS);
}

int show_setting(game_t *game)
{
    return (SUCCESS);
}

buttons_t *setting_button(buttons_t *button)
{
    button->type = MENU_SETTINGS;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/settings.png", NULL);
    button->hover = sfTexture_createFromFile(\
    "ressources/sprites/menu/settings2.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1770;
    button->pos.y = 900;
    button->hitbox_pos = init_vec2f(1802, 905);
    button->size = init_vec2f(93, 92);
    button->callback = &show_setting;
    return (button);
}

buttons_t *exit_button(buttons_t *button)
{
    button->type = MENU_EXIT;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/exit.png", NULL);
    button->hover = sfTexture_createFromFile(\
    "ressources/sprites/menu/exit2.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1650;
    button->pos.y = 900;
    button->hitbox_pos = init_vec2f(1682, 905);
    button->size = init_vec2f(93, 92);
    button->callback = &leave_the_game;
    return (button);
}
