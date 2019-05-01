/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display house 1
*/

#include "my_rpg.h"

game_t *events_house(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
    return game;
}

game_t *display_house_1(game_t *game)
{
    //game->scenes->objs->game_object = sort_game_object(game->scenes->objs->game_object);
    move_all_the_scene(game);
    display_bg(game);
    display_game_object(game);
    display_inventory(game);
    display_quests(game);
    game = events_house(game);
    return (game);
}
