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

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

game_t *idle_play_button(game_t *game, char *str, char *str2)
{
    buttons_t *button = game->scenes->buttons;

    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START; button = button->next);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(\
    str, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    for (; button->prev != NULL; button = button->prev);
    for (; button->type != START_2; button = button->next);
    button->sprite = sfSprite_create();
    button->texture = sfTexture_createFromFile(\
    str2, NULL);
    sfSprite_setPosition(button->sprite, button->pos);
    sfSprite_setTexture(button->sprite, button->texture, sfFalse);
    sfRenderWindow_drawSprite(game->window, button->sprite, NULL);
    return (game);
}



game_t *idle_events(game_t *game)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(game->window);

    if (mouse_pos.x >= 830 && mouse_pos.x <= 1380 && \
        mouse_pos.y >= 200 && mouse_pos.y <= 350)
        game = idle_play_button(game, \
        "../../ressources/sprites/menu/danseur.png", \
        "../../ressources/sprites/menu/danseur.png");
    else
        game = idle_play_button(game, \
        "../../ressources/sprites/menu/buttonplay1.png", \
        "../../ressources/sprites/menu/buttonplay2.png");
    return (game);
}

game_t *display_menu(game_t *game)
{
    background_t *background = game->scenes->objs->background;

    game = idle_events(game);
    event_pressed(game);
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
    display_play_button(game);
    return (game);
}
