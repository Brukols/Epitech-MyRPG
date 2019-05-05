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
    if (my_strcmp(pnj->name, "Dobby") == 0)
        music_play(game->scenes->musics, ALIEN_SOUND, sfFalse);
    if (my_strcmp(pnj->name, "Master") == 0)
        music_play(game->scenes->musics, DARK_SOUND, sfFalse);
    if (my_strcmp(pnj->name, "Joker") == 0)
        music_play(game->scenes->musics, JOKER_SOUND, sfFalse);
    if (my_strcmp(pnj->name, "Leader") == 0)
        music_play(game->scenes->musics, LEADER_SOUND, sfFalse);
}

void stop_music_voice(game_t *game, pnj_t *pnj)
{
    if (my_strcmp(pnj->name, "Freddy") == 0 || \
my_strcmp(pnj->name, "Zoro") == 0 || my_strcmp(pnj->name, "Guard") == 0)
        music_stop(game->scenes->musics, VOICE_M);
    if (my_strcmp(pnj->name, "Ariana") == 0 || \
my_strcmp(pnj->name, "Lucy") == 0)
        music_stop(game->scenes->musics, VOICE_F);
    if (my_strcmp(pnj->name, "Dobby") == 0)
        music_stop(game->scenes->musics, ALIEN_SOUND);
    if (my_strcmp(pnj->name, "Master") == 0)
        music_stop(game->scenes->musics, DARK_SOUND);
    if (my_strcmp(pnj->name, "Joker") == 0)
        music_stop(game->scenes->musics, JOKER_SOUND);
    if (my_strcmp(pnj->name, "Leader") == 0)
        music_stop(game->scenes->musics, LEADER_SOUND);
}
