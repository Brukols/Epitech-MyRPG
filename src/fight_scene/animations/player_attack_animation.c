/*
** EPITECH PROJECT, 2019
** player_attack_animation.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void player_attack_animation(game_t *game)
{
    game_object_t *obj = game->scenes->objs->player->game_object;
    sfTime time = sfClock_getElapsedTime(obj->clock);
    float seconds = sfTime_asSeconds(time);
    sfVector2f pos = {obj->pos.x + 50, obj->pos.y};

    if (game->scenes->objs->player->attacking) {
        if (seconds < 2.0) {
            sfSprite_setPosition(obj->sprite, pos);
            update_enemy_pos(game);
        } else {
            game->scenes->objs->player->attacking = false;
            sfSprite_setPosition(obj->sprite, obj->pos);
            sfSprite_setPosition(game->scenes->objs->enemy->obj->sprite, \
            game->scenes->objs->enemy->obj->pos);
        }
    }
}

void update_enemy_pos(game_t *game)
{
    static bool status = false;
    game_object_t *obj = game->scenes->objs->enemy->obj;
    sfVector2f pos = {obj->pos.x, obj->pos.y};

    if (!status) {
        status = true;
        pos.x += 30;
    } else {
        status = false;
        pos.x -= 30;
    }
    sfSprite_setPosition(obj->sprite, pos);
}
