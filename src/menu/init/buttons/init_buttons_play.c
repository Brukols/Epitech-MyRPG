/*
** EPITECH PROJECT, 2019
** inits play butons sprites
** File description:
** rpg
*/

#include "my_rpg.h"

game_t *go_to_the_game(game_t *game)
{
    for (; game->scenes->scene != FIRST_SCENE; \
    game->scenes = game->scenes->next);
    return (game);
}

buttons_t *button_play(buttons_t *button)
{
    button->type = START;
    button->texture = sfTexture_createFromFile(\
    "ressources/sprites/menu/buttonplay.png", NULL);
    button->hover = sfTexture_createFromFile(\
    "ressources/sprites/menu/danseur.png", NULL);
    button->sprite = sfSprite_create();
    button->pos.x = 750;
    button->pos.y = 450;
    button->rect = init_intrect(0, 0, 480, 320);
    button->hitbox_pos = init_vec2f(785, 550);
    button->size = init_vec2f(400, 100);
    button->clock = sfClock_create();
    button->callback = &go_to_the_game;
    return (button);
}