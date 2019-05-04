/*
** EPITECH PROJECT, 2019
** init_musci_fs_scene
** File description:
** my_rpg
*/

#include "my_rpg.h"

musics_t *wind_sound(musics_t *music)
{
    music->type = WIND_SOUND;
    music->music = sfMusic_createFromFile("ressources/music/wind_rpg.ogg");
    if (!music->music)
        return (NULL);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}

musics_t *run_sound(musics_t *music)
{
    music->type = RUN_SOUND;
    music->music = sfMusic_createFromFile("ressources/music/run_rpg.ogg");
    if (!music->music)
        return (NULL);
    return (music);
}

musics_t *open_chest_sound(musics_t *music)
{
    music->type = OPEN_CHEST_SOUND;
    music->music = sfMusic_createFromFile("ressources/music/open.ogg");
    if (!music->music)
        return (NULL);
    return (music);
}

musics_t *init_musics_fs_scene(void)
{
    musics_t *musics = malloc(sizeof(musics_t));
    musics_t *(*fill_musics_fs_scene[])() = {wind_sound, run_sound, \
        open_chest_sound};

    if (!musics)
        return (NULL);
    musics->prev = NULL;
    for (int i = 0; i < 3; i++) {
        musics = fill_musics_fs_scene[i](musics);
        if (!musics)
            return (NULL);
        if (i == 2)
            break;
        if (!(musics->next = malloc(sizeof(musics_t))))
            return (NULL);
        musics->next->prev = musics;
        musics = musics->next;
    }
    musics->next = NULL;
    for (; musics->prev; musics = musics->prev);
    return (musics);
}