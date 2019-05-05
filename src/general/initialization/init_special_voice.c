/*
** EPITECH PROJECT, 2019
** init_special_voice
** File description:
** my_rpg
*/

#include "my_rpg.h"

musics_t *joker_sound(musics_t *music)
{
    music->type = JOKER_SOUND;
    music->pause = false;
    music->stop = true;
    music->music = sfMusic_createFromFile("ressources/music/joker.ogg");
    if (!music->music)
        return (NULL);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}

musics_t *alien_sound(musics_t *music)
{
    music->type = ALIEN_SOUND;
    music->pause = false;
    music->stop = true;
    music->music = sfMusic_createFromFile("ressources/music/alien.ogg");
    if (!music->music)
        return (NULL);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}

musics_t *dark_sound(musics_t *music)
{
    music->type = DARK_SOUND;
    music->pause = false;
    music->stop = true;
    music->music = sfMusic_createFromFile("ressources/music/dark.ogg");
    if (!music->music)
        return (NULL);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}

musics_t *leader_sound(musics_t *music)
{
    music->type = LEADER_SOUND;
    music->pause = false;
    music->stop = true;
    music->music = sfMusic_createFromFile("ressources/music/leader.ogg");
    if (!music->music)
        return (NULL);
    sfMusic_setLoop(music->music, sfTrue);
    return (music);
}