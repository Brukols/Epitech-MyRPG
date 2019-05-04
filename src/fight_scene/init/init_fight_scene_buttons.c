/*
** EPITECH PROJECT, 2019
** init_fight_scene_buttons.c
** File description:
** init_fight_scene_buttons.c
*/

#include "my_rpg.h"

buttons_t *init_fight_scene_buttons(void)
{
    buttons_t *button = malloc(sizeof(buttons_t));
    buttons_t *(*init_fight_button[4])() = {attack_button, magic_button, \
        escape_button, info_button};

    if (button == NULL)
        return (NULL);
    button->prev = NULL;
    for (int i = 0; i < 4; i++) {
        if ((button = init_fight_button[i](button)) == NULL)
            return (NULL);
        if (i == 3)
            break;
        button->next = malloc(sizeof(buttons_t));
        if (button->next == NULL)
            return (NULL);
        button->next->prev = button;
        button = button->next;
    }
    button->next = NULL;
    for (; button->prev; button = button->prev);
    return (button);
}

buttons_t *attack_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=300, .height=134};

    button->type = ATTACK;
    button->pos = init_vec2f(60.0, 890.0);
    button->size = init_vec2f(300.0, 134.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = true;
    button->texture = sfTexture_createFromFile(ATTACK_BUTTON, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->callback = &player_basic_attack;
    return (button);
}

buttons_t *magic_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=300, .height=134};

    button->type = MAGIC;
    button->pos = init_vec2f(410.0, 890.0);
    button->size = init_vec2f(300.0, 134.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = true;
    button->texture = sfTexture_createFromFile(MAGIC_BUTTON, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->callback = &player_magic_attack;
    return (button);
}

buttons_t *escape_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=300, .height=134};

    button->type = ESCAPE;
    button->pos = init_vec2f(760.0, 890.0);
    button->size = init_vec2f(300.0, 134.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = true;
    button->texture = sfTexture_createFromFile(ESCAPE_BUTTON, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->callback = &escape_fight_scene;
    return (button);
}

buttons_t *info_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=110, .height=110};

    button->type = INFO;
    button->pos = init_vec2f(1800.0, 0.0);
    button->size = init_vec2f(300.0, 134.0);
    button->rect = rect;
    button->clock = NULL;
    button->hitbox_pos = button->pos;
    button->display = true;
    button->texture = sfTexture_createFromFile(FIGHT_INFO_BUTTON, NULL);
    button->sprite = sfSprite_create();
    if (button->texture == NULL || button->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTextureRect(button->sprite, button->rect);
    button->callback = &display_info;
    return (button);
}
