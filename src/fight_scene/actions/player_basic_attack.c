/*
** EPITECH PROJECT, 2019
** player_basic_attack.c
** File description:
** my_rpg
*/

#include "my_rpg.h"

int player_basic_attack(game_t *game)
{
    int attack_status = rand_basic_attack(rand_action(100));
    char *msg = "PLAYER attacks: ";
    char *(*make_msg[3])(game_t *, char *) = {make_failed_attack_msg, \
        make_normal_attack_msg, make_powerful_attack_msg, };

    if (!game->scenes->objs->player->attacking) {
        if ((msg = make_msg[attack_status](game, msg)) == NULL)
            return (ERROR);
        sfText_setString(game->scenes->texts->text, msg);
        display_fight_scene(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
        if (wait_n_seconds(2.5) == ERROR)
            return (ERROR);
        if (game->scenes->objs->player->attacking)
            calcul_basic_attack(attack_status, game);
        enemy_attack(game);
        game->scenes->objs->player->attacking = false;
    }
    return (0);
}

char *make_normal_attack_msg(game_t *game, char *msg)
{
    char *attack = nbr_to_str(game->scenes->objs->player->attack);

    if (attack == NULL)
        return (NULL);
    game->scenes->objs->player->attacking = true;
    msg = my_strdupcat(msg, "success!\nENEMY takes ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, attack);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}

char *make_powerful_attack_msg(game_t *game, char *msg)
{
    char *attack = nbr_to_str(game->scenes->objs->player->attack * 2);

    if (attack == NULL)
        return (NULL);
    game->scenes->objs->player->attacking = true;
    msg = my_strdupcat(msg, "CRITICAL STRIKE!\nENEMY takes ");
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, attack);
    if (msg == NULL)
        return (NULL);
    msg = my_strdupcat(msg, " damage.");
    if (msg == NULL)
        return (NULL);
    return (msg);
}

char *make_failed_attack_msg(__attribute__((unused)) game_t *game, char *msg)
{
    msg = my_strdupcat(msg, "it failed!");
    if (msg == NULL)
        return (NULL);
    return (msg);
}
