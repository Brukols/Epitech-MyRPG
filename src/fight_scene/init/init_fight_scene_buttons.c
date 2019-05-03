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
    buttons_t *(*init_fight_button[6])() = {attack_button, magic_button, \
        escape_button, enemy_button_one, enemy_button_two, enemy_button_three};

    if (button == NULL)
        return (NULL);
    button->prev = NULL;
    for (int i = 0; i < 6; i++) {
        if ((button = init_fight_button[i](button)) == NULL)
            return (NULL);
        if (i == 5)
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
    button->pos = init_vec2f(100.0, 890.0);
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
    button->callback = &player_attack;
    return (button);
}

buttons_t *magic_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=300, .height=134};

    button->type = MAGIC;
    button->pos = init_vec2f(450.0, 890.0);
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
    //button->callback = &magic;
    return (button);
}

buttons_t *escape_button(buttons_t *button)
{
    sfIntRect rect = {.left=0, .top=0, .width=300, .height=134};

    button->type = ESCAPE;
    button->pos = init_vec2f(800.0, 890.0);
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
    //button->callback = &escape;
    return (button);
}
