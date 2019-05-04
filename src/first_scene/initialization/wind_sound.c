/*
** EPITECH PROJECT, 2019
** win_doun
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
    return (music);
}