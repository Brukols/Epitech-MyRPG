/*
** EPITECH PROJECT, 2019
** player_magic_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int player_magic_attack(game_t *game)
{
    int attack_status = rand_action(100);
    char *msg = "PLAYER attacks with MAGIC: ";

    if (attack_status >= 50) {
        msg = make_magic_attack_msg(game, msg);
        calcul_magic_attack(game);
    } else
        msg = make_failed_attack_msg(game, msg);
    if (msg == NULL)
        return (ERROR);
    sfText_setString(game->scenes->texts->text, msg);
    display_fight_scene(game);
    sfRenderWindow_display(game->window);
    sfRenderWindow_clear(game->window, sfBlack);
    if (wait_n_seconds(1.5) == ERROR)
        return (ERROR);
    enemy_attack(game);
    return (0);
}

char *make_magic_attack_msg(game_t *game, char *msg)
{
    char *power = nbr_to_str(game->scenes->objs->player->power);

    msg = my_strdupcat(msg, "success!\n ENEMY takes ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, power);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}
