/*
** EPITECH PROJECT, 2019
** enemy_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int enemy_attack(game_t *game)
{
    char *msg = make_enemy_attack_msg(game, "ENEMY attacks: you take ");

    if (msg == NULL)
        return (-1);
    sfText_setString(game->scenes->texts->text, msg);
    display_fight_scene(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    if (wait_n_seconds(1.5) == ERROR)
        return (ERROR);
    game->scenes->objs->player->hp -= game->scenes->objs->enemy->attack;
    if (game->scenes->objs->player->hp < 0)
        game->scenes->objs->player->hp = 0;
    return (0);
}

char *make_enemy_attack_msg(game_t *game, char *msg)
{
    char *atk = nbr_to_str(game->scenes->objs->enemy->attack);

    msg = my_strdupcat(msg, atk);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}
