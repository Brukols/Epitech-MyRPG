/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** display bubbles
*/

#include "my_rpg.h"

game_t *bubble_1(game_t *game)
{
     game_object_t *bubble = NULL;
     background_t *background = game->scenes->objs->background;

     sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
     game = select_bubble_1(game);
     bubble = game->scenes->objs->game_object;
     sfSprite_setPosition(bubble->sprite, bubble->pos);
     sfSprite_setTexture(bubble->sprite, bubble->texture, sfFalse);
     sfRenderWindow_drawSprite(game->window, bubble->sprite, NULL);
     return (game);
}

game_t *bubble_2(game_t *game)
{
    game_object_t *bubble = NULL;
    background_t *background = game->scenes->objs->background;

    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    game = select_bubble_2(game);
    bubble = game->scenes->objs->game_object;
    sfSprite_setPosition(bubble->sprite, bubble->pos);
    sfSprite_setTexture(bubble->sprite, bubble->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, bubble->sprite, NULL);
    return (game);
}

game_t *bubble_3(game_t *game)
{
    game_object_t *bubble = NULL;
    background_t *background = game->scenes->objs->background;

    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    game = select_bubble_3(game);
    bubble = game->scenes->objs->game_object;
    sfSprite_setPosition(bubble->sprite, bubble->pos);
    sfSprite_setTexture(bubble->sprite, bubble->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, bubble->sprite, NULL);
    return (game);
}
