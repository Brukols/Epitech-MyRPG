/*
** EPITECH PROJECT, 2019
** rpg
** File description:
** display house 1
*/

#include "my_rpg.h"

void change_player_position_up_and_down(player_t *player, \
background_t *bg, sfKeyCode code, bool move)
{
    if (code == sfKeyDown) {
        player->game_object->move_y = (move ? 1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->down;
    }
    if (code == sfKeyUp) {
        player->game_object->move_y = (move ? -1 : 0);
        player->game_object->move_x = 0;
        player->game_object->rect.top = player->up;
    }
}

void change_position_player(player_t *player, background_t *bg, sfKeyCode code,
bool move)
{
    if (code == sfKeyRight) {
        player->game_object->move_x = (move ? 1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->right;
    }
    if (code == sfKeyLeft) {
        player->game_object->move_x = (move ? -1 : 0);
        player->game_object->move_y = 0;
        player->game_object->rect.top = player->left;
    }
    change_player_position_up_and_down(player, bg, code, move);
}

void move_on_the_house(game_t *game, sfKeyCode code, bool move)
{
    background_t *bg = game->scenes->objs->background;
    player_t *player = game->scenes->objs->player;

    if (code == sfKeyEscape)
        sfRenderWindow_close(game->window);
    change_position_player(player, bg, code, move);
}

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
        if (event.type == sfEvtKeyReleased)
            move_on_the_house(game, event.key.code, false);
    }
    return game;
}

bool will_touch_house_side(game_object_t *player, game_object_t *go, \
sfVector2f pos_player)
{
    if (player->move_x < 0 && pos_player.x + 10 > go->hitbox_pos.x &&   \
        pos_player.x + 10 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 85 > go->hitbox_pos.y && pos_player.y + 85 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    if (player->move_x > 0 && pos_player.x + 65 > go->hitbox_pos.x && \
        pos_player.x + 65 < go->hitbox_pos.x + go->hitbox_size.x && \
        pos_player.y + 85 > go->hitbox_pos.y && pos_player.y + 85 < \
        go->hitbox_pos.y + go->hitbox_size.y)
        return (true);
    return (false);
}

bool will_touch_house_up_and_down(game_object_t *player, game_object_t *go, \
sfVector2f pos_player)
{
    if (player->move_y < 0 && pos_player.y + 80 > go->hitbox_pos.y && \
        pos_player.y + 80 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 60 > go->hitbox_pos.x && pos_player.x + 20 < \
        go->hitbox_pos.x + go->hitbox_size.x)
        return (true);
    if (player->move_y > 0 && pos_player.y + 5 + 100 > go->hitbox_pos.y && \
        pos_player.y + 5 + 100 < go->hitbox_pos.y + go->hitbox_size.y && \
        pos_player.x + 60 > go->hitbox_pos.x && pos_player.x + 20 < \
        go->hitbox_pos.x + go->hitbox_size.x)
        return (true);
    return (false);
}

void move_player_in_x_y(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    game_object_t *player = game->scenes->objs->player->game_object;
    sfVector2f pos_pla = init_vec2f(player->pos.x, player->pos.y);

    if (player->move_x > 0)
        player->pos.x += 5;
    if (player->move_x < 0)
        player->pos.x -= 5;
    if (player->move_y > 0) {
        player->pos.y += 5;
        player->comparison += 5;
    }
    if (player->move_y < 0) {
        player->pos.y -= 5;
        player->comparison -= 5;
    }
}

bool player_touch_smth_in_house(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    game_object_t *player = game->scenes->objs->player->game_object;
    sfVector2f pos_pla = init_vec2f(player->pos.x, player->pos.y);

    for (; go; go = go->next) {
        if (will_touch_house_up_and_down(player, go, pos_pla) == true || \
            will_touch_house_side(player, go, pos_pla) == true) {
            player->move_x = 0;
            player->move_y = 0;
            return true;
        }
    }
    return false;
}

void move_player_on_the_house(game_t *game)
{
    if (player_touch_smth_in_house(game) == true)
        return;
    move_player_in_x_y(game);
}

game_t *display_player_house(game_t *game)
{
    move_player_on_the_house(game);
    game->scenes->objs->game_object = sort_game_object(game->scenes->objs->game_object);
    display_player(game);
    display_bg(game);
    display_game_object(game);
    display_inventory(game); //reprendre l'init
    display_quests(game);
    game = events_house(game);
    return (game);
}
