/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** select bubble list
*/

#include "my_rpg.h"

game_t *select_bubble_4(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE4; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_bubble_5(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE5; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_king_walk(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_KING_WALK; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_king_surprise(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_KING_SURPRISE; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->next);
    return (game);
}

game_t *select_red_bubble(game_t *game)
{
    for (; game->scenes->objs->game_object->prev != NULL; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->prev);
    for (;game->scenes->objs->game_object->type != INTRO_BUBBLE_RED; \
    game->scenes->objs->game_object = \
    game->scenes->objs->game_object->next);
    return (game);
}