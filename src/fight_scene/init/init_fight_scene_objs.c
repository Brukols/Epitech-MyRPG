/*
** EPITECH PROJECT, 2019
** init_fight_scene_objs.c
** File description:
** init_fight_scene_objs.c
*/

#include "my_rpg.h"

scene_object_t *init_fight_scene_objs(scenes_t *scene)
{
    scene_object_t *obj = malloc(sizeof(scene_object_t));

    if (obj == NULL)
        return (NULL);
    obj->background = init_fight_scene_background();
    obj->game_object = init_fight_scene_game_objects();
    obj->player = init_fight_scene_player(scene);
    obj->enemy = init_enemies();
    obj->clicks = NULL;
    obj->pnj = NULL;
    if (obj->background == NULL || obj->game_object == NULL || \
        obj->player == NULL || obj->enemy == NULL) {
        free(obj);
        return (NULL);
    }
    return (obj);
}

background_t *init_fight_scene_background(void)
{
    background_t *bg = malloc(sizeof(background_t));

    if (bg == NULL)
        return (NULL);
    bg->pos = init_vec2f(0, 0);
    bg->clock = NULL;
    bg->move_x = 0;
    bg->move_y = 0;
    bg->texture = sfTexture_createFromFile(BG_FIGHT, NULL);
    bg->sprite = sfSprite_create();
    if (bg->texture == NULL || bg->sprite == NULL) {
        free(bg);
        return (NULL);
    }
    sfSprite_setTexture(bg->sprite, bg->texture, sfFalse);
    sfSprite_setPosition(bg->sprite, bg->pos);
    return (bg);
}

player_t *init_fight_scene_player(scenes_t *scene)
{
    player_t *player = malloc(sizeof(player_t));
    inventory_t *inventory = scene->prev->prev->objs->player->inventory;

    if (player == NULL)
        return (NULL);
    player->inventory = inventory;
    player->hp = 100;
    player->attack = 50;
    player->attacking = false;
    player->game_object = init_fight_scene_player_object();
    if (player->game_object == NULL) {
        free(player);
        return (NULL);
    }
    return (player);
}

game_object_t *init_fight_scene_player_object(void)
{
    game_object_t *obj = malloc(sizeof(game_object_t));

    if (obj == NULL)
        return (NULL);
    obj->type = PLAYER;
    obj->pos = init_vec2f(450, 400);
    obj->rect = init_intrect(78, 0, 78, 108);
    obj->scale = init_vec2f(2, 2);
    obj->clock = sfClock_create();
    obj->texture = sfTexture_createFromFile(PLAYER_SHEET, NULL);
    obj->sprite = sfSprite_create();
    if (obj->texture == NULL || obj->sprite == NULL || obj->clock == NULL) {
        free(obj);
        return (NULL);
    }
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setScale(obj->sprite, obj->scale);
    return (obj);
}
