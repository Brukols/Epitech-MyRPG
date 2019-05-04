/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** display_fight_scene.c
*/

#include "my_rpg.h"

game_t *display_fight_scene(game_t *game)
{
    display_fight_scene_objs(game);
    display_enemies(game);
    sfRenderWindow_drawText(game->window, game->scenes->texts->text, NULL);
    display_fight_scene_buttons(game);
    return (game);
}

void display_fight_scene_buttons(game_t *game)
{
    buttons_t *button = game->scenes->buttons;

    while (button->prev != NULL)
        button = button->prev;
    while (button != NULL) {
        if (button->display == true)
            sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
        button = button->next;
    }
}

void display_fight_scene_objs(game_t *game)
{
    game_object_t *obj = game->scenes->objs->game_object;

    sfRenderWindow_drawSprite(game->window, \
    game->scenes->objs->background->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, \
    game->scenes->objs->player->game_object->sprite, NULL);
    while (obj != NULL) {
        if (obj->display)
            sfRenderWindow_drawSprite(game->window, obj->sprite, NULL);
        obj = obj->next;
    }
}

void display_enemies(game_t *game)
{
    enemy_t *enemy = game->scenes->objs->enemy;

    sfRenderWindow_drawSprite(game->window,  \
    enemy->obj->sprite, NULL);
}
