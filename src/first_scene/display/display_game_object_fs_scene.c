/*
** EPITECH PROJECT, 2019
** display_game_objec_fs_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_game_object_fs_scene(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;

    for (; go; go = go->next) {
        sfSprite_setPosition(go->sprite, go->pos);
        sfSprite_setTexture(go->sprite, go->texture, sfFalse);
        sfSprite_setTextureRect(go->sprite, go->rect);
        if (go->type != PLAYER)
            sfSprite_setScale(go->sprite, go->scale);
        sfRenderWindow_drawSprite(game->window, go->sprite, NULL);
    }
}