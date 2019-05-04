/*
** EPITECH PROJECT, 2019
** player_attack_animation.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

void player_attack_animation(game_t *game)
{
    static bool anim_running = false;
    game_object_t *obj = game->scenes->objs->player->game_object;
    sfTime time = sfClock_getElapsedTime(obj->clock);
    float seconds = sfTime_asSeconds(time);
    sfVector2f pos = {obj->pos.x + 50, obj->pos.y};

    if (!anim_running) {
        anim_running = true;
        sfClock_restart(obj->clock);
    }
    if (anim_running == true && seconds < 1.0) {
        printf("running\n");
        sfSprite_setPosition(obj->sprite, pos);
        update_enemy_pos(game);
    } else if (anim_running == true && seconds > 1.0) {
        printf("end\n");
        anim_running = false;
        game->scenes->objs->player->attacking = false;
        sfSprite_setPosition(obj->sprite, obj->pos);
        sfClock_restart(obj->clock);
    }
}

void update_enemy_pos(game_t *game)
{
    static bool status = false;
    game_object_t *obj = game->scenes->objs->enemy->obj;
    sfVector2f pos = {obj->pos.x, obj->pos.y};

    if (!status) {
        status = true;
        pos.x += 40;
    } else {
        status = true;
        pos.x -= 80;
    }
    sfSprite_setPosition(obj->sprite, pos);
}
