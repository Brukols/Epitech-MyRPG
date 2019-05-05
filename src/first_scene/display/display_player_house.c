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
        if (event.type == sfEvtMouseButtonReleased)
            manage_mouse_button_event(game);
        if (event.type == sfEvtKeyPressed)
            move_on_the_house(game, event.key.code, true);
        if (event.type == sfEvtKeyReleased) {
            move_on_the_house(game, event.key.code, false);
            interactions(game, event.key.code);
        }
    }
    return game;
}

game_t *display_player_house(game_t *game)
{
    if (go_back_to_first_scene(game) == true)
        return (game);
    move_player_on_the_house(game);
    game->scenes->objs->game_object = sort_game_object(\
    game->scenes->objs->game_object);
    display_player(game);
    display_bg(game);
    display_game_object(game);
    display_inventory(game);
    display_quests(game, sfRed);
    display_buttons(game);
    display_status_menu(game);
    display_texts_house_player(game);
    game = events_house(game);
    return (game);
}
