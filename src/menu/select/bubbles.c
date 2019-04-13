/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** select bubbles
*/

#include "my_rpg.h"

game_t *select_fairy(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_FAIRY; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_bubble_1(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE1; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_bubble_2(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE2; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_bubble_3(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE3; \
         game->scenes->objs->game_object = \
         game->scenes->objs->game_object->next);
    return (game);
}
