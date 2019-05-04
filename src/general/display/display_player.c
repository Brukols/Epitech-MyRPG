/*
** EPITECH PROJECT, 2019
** display_first_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

void display_player(game_t *game)
{
    static int i = 0;
    game_object_t *player = game->scenes->objs->player->game_object;
    musics_t *music = game->scenes->musics;

    for (; music->type != RUN_SOUND; music = music->next);
    if (player->move_x || player->move_y) {
        if (i == 0) {
            sfMusic_play(music->music);
            sfMusic_setLoop(music->music, sfTrue);
            i++;
        }
        if (sfClock_getElapsedTime(player->clock).microseconds > 120000) {
            player->rect.left += 78;
            sfClock_restart(player->clock);
        }
        if (player->rect.left == 234)
            player->rect.left = 0;
    } else {
        i = 0;
        sfMusic_pause(music->music);
        player->rect.left = 78;
    }
}
