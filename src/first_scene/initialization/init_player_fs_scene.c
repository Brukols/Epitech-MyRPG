/*
** EPITECH PROJECT, 2019
** inti_player
** File description:
** my_rpg
*/

#include "my_rpg.h"

player_t *init_player_fs_scene(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    if (!(player->texture = sfTexture_createFromFile(\
        "ressources/sprites/chara5.png", NULL)))
        return (NULL);
    if (!(player->sprite = sfSprite_create()))
        return (NULL);
    player->pos = init_vec2f(900, 480);
    player->rect = init_intrect(78, 0, 78, 108);
    player->move_x = 0;
    player->move_y = 0;
    player->clock = sfClock_create();
    return (player);
}