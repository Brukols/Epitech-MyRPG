/*
** EPITECH PROJECT, 2019
** intereactin_with_other_chest
** File description:
** my_rpg
*/

#include "my_rpg.h"

bool manage_other_chest(game_t *game, game_object_t *go)
{
    musics_t *music = game->scenes->musics;
    slot_t *slot = game->scenes->objs->player->inventory->slots;
    inventory_t *inventory = game->scenes->objs->player->inventory;

    music_play(music, OPEN_CHEST_SOUND, sfFalse);
    add_item(inventory, go->item);
    actualize_stats_player(game, go->item, 1.3);
    go->open = true;
    go->rect.top += 108;
    if (go->type == SECOND_CHEST) {
        game->quests->quest++;
        game->quests->all_quests++;
    }
    return (true);
}

bool interaction_with_other_chest(game_t *game)
{
    game_object_t *go = game->scenes->objs->game_object;
    player_t *player = game->scenes->objs->player;

    for (; go; go = go->next) {
        if (go->type != SECOND_CHEST || go->display == false)
            continue;
        if (go->open == true)
            continue;
        if (player_touch_chest(go, player->game_object) != true)
            continue;
        return (manage_other_chest(game, go));
    }
    return (false);
}