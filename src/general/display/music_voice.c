/*
** EPITECH PROJECT, 2019
** music_voice
** File description:
** my_rpg
*/

#include "my_rpg.h"

void play_music_voice(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->name, "Freddy") == 0 || \
    my_strcmp(pnj->name, "Zoro") == 0 || my_strcmp(pnj->name, "Guard") == 0)
        music_play(game->scenes->musics, VOICE_M, sfFalse);
    if (my_strcmp(pnj->name, "Ariana") == 0 || \
    my_strcmp(pnj->name, "Lucy") == 0)
        music_play(game->scenes->musics, VOICE_F, sfFalse);
}

void pause_music_voice(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->name, "Freddy") == 0 || \
    my_strcmp(pnj->name, "Zoro") == 0 || my_strcmp(pnj->name, "Guard") == 0)
        music_pause(game->scenes->musics, VOICE_M);
    if (my_strcmp(pnj->name, "Ariana") == 0 || \
    my_strcmp(pnj->name, "Lucy") == 0)
        music_pause(game->scenes->musics, VOICE_F);
}