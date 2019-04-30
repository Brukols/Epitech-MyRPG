/*
** EPITECH PROJECT, 2019
** display_fight_scene.c
** File description:
** display_fight_scene.c
*/

#include "my_rpg.h"

game_t *display_fight(game_t *game)
{
    int nb = game->quest->all_quests;
    sfRenderWindow *window = game->window;
    player_t *player = game->scenes->objs->player;

    
    return (game);
}

game_t display_fight_scene(game_t *game)
{
    for (int i = 0; i < scene->nb_object; i++) {
        sfSprite_setPosition(scene->object[i]->sprite,
                             scene->object[i]->position);
        sfRenderWindow_drawSprite(window, scene->object[i]->sprite, NULL);
    }
    for (int i = 0; i < scene->nb_button; i++) {
        sfSprite_setPosition(scene->button[i]->sprite,
                             scene->button[i]->position);
        sfRenderWindow_drawSprite(window, scene->button[i]->sprite, NULL);
        sfRenderWindow_drawRectangleShape(window, scene->button[i]->shape,
        NULL);
    }
}
