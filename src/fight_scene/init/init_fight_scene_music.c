/*
** EPITECH PROJECT, 2019
** init_fight_scene_music.c
** File description:
** init_fight_scene_music.c
*/

#include "my_rpg.h"

musics_t *init_fight_scene_music(void)
{
    musics_t *music = malloc(sizeof(musics_t));

    if (music == NULL)
        return (NULL);
    music->music = sfMusic_createFromFile(FIGHT_MUSIC);
    if (music->music == NULL)
        return (NULL);
    music->next = NULL;
    music->prev = NULL;
    sfMusic_play(music->music);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}
