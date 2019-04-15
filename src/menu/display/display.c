/*
** EPITECH PROJECT, 2019
** display all elements
** File description:
** rpg
*/

#include "my_rpg.h"

void event_pressed(game_t *game)
{
    sfEvent event;
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (mouse_pos.x >= 1820 && mouse_pos.x <= 1920 &&   \
        mouse_pos.y >= 900 && mouse_pos.y <= 1000 && \
        event.mouseButton.type == sfEvtMouseButtonPressed)
        sfRenderWindow_close(game->window);
    }
}

game_t *idle_events(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    redirect_idle_play_button(mouse_pos, game);
    idle_bottoms_buttons(mouse_pos, game);
    return (game);
}

game_t *display_menu(game_t *game)
{
    background_t *background = NULL;

    for (; game->scenes->prev != NULL; game->scenes = game->scenes->prev);
    for (; game->scenes->scene != MENU; game->scenes = game->scenes->next);
    background = game->scenes->objs->background;
    game = idle_events(game);
    event_pressed(game);
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    display_play_button(game);
    display_statics_buttons(game);
    sfRenderWindow_drawText(game->window, game->scenes->texts->text, NULL);
    return (game);
}
