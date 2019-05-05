/*
** EPITECH PROJECT, 2019
** my_rog
** File description:
** init_buttons_fs_scene
*/

#include "my_rpg.h"

buttons_t *init_music_button(buttons_t *button)
{
    button->display = true;
    button->display_hover = false;
    button->type = BUTTON_SETTINGS_MUSIC;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/settings/music.png", NULL);
    button->hover = sfTexture_createFromFile(\
    "ressources/sprites/settings/stop.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 350;
    button->pos.y = 430;
    button->hitbox_pos = init_vec2f(350, 430);
    button->size = init_vec2f(112, 309);
    button->clock = sfClock_create();
    button->callback = &cut_music;
    button->rect = init_intrect(0, 0, 422, 720);
    return (button);
}

buttons_t *init_exit_button(buttons_t *button)
{
    button->display = true;
    button->type = BUTTON_SETTINGS_EXIT;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/exit.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1600;
    button->pos.y = 900;
    button->hitbox_pos = init_vec2f(1600, 900);
    button->size = init_vec2f(93, 92);
    button->callback = &leave_the_game;
    button->rect = init_intrect(0, 0, 600, 400);
    return (button);
}

buttons_t *init_cancel_button(buttons_t *button)
{
    button->display = true;
    button->type = BUTTON_SETTINGS_EXIT;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/settings/quit.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1500;
    button->pos.y = 900;
    button->hitbox_pos = init_vec2f(1500, 900);
    button->size = init_vec2f(93, 92);
    button->callback = &return_fs_scene;
    button->rect = init_intrect(0, 0, 600, 400);
    return (button);
}

buttons_t *init_home_button(buttons_t *button)
{
    button->display = true;
    button->type = BUTTON_SETTINGS_EXIT;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/settings/home.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 1380;
    button->pos.y = 900;
    button->hitbox_pos = init_vec2f(1380, 900);
    button->size = init_vec2f(93, 92);
    button->callback = &return_menu_scene;
    button->rect = init_intrect(0, 0, 600, 400);
    return (button);
}

buttons_t *init_settings(void)
{
    buttons_t *buttons = malloc(sizeof(buttons_t));
    buttons_t *(*fill_buttons[])() = {init_music_button, init_exit_button, \
init_cancel_button, init_home_button};

    if (!buttons)
        return (NULL);
    buttons->prev = NULL;
    for (int i = 0; i < 4; i++) {
        buttons = fill_buttons[i](buttons);
        if (!buttons)
            return (NULL);
        if (i == 3)
            break;
        if (!(buttons->next = malloc(sizeof(buttons_t))))
            return (NULL);
        buttons->next->prev = buttons;
        buttons = buttons->next;
    }
    buttons->next = NULL;
    for (; buttons->prev; buttons = buttons->prev);
    return (buttons);
}
