/*
** EPITECH PROJECT, 2019
** my_rpg
** File description:
** init_items
*/

#include "my_rpg.h"

void *create_item_with_id(int number)
{
    void(*tab_func[15]);

    tab_func[0] = create_sword;
    tab_func[1] = create_ring;
    tab_func[2] = create_key;
    tab_func[3] = create_amulet;
    tab_func[4] = create_banana;
    tab_func[5] = create_chaos;
    tab_func[6] = create_cloak;
    tab_func[7] = create_helmet;
    tab_func[8] = create_katana;
    tab_func[9] = create_potion;
    tab_func[10] = create_speelbook;
    tab_func[11] = create_star;
    tab_func[12] = create_vulcan;
    tab_func[13] = create_wand;
    tab_func[14] = NULL;
    return (tab_func[number]);
}

item_t *create_one_item(int id)
{
    item_t *(*pointeurOnFunction)(void);

    pointeurOnFunction = create_item_with_id(id);
    return (pointeurOnFunction());
}

item_t **create_all_items(item_t **items)
{
    items[0] = create_one_item(0);
    items[1] = create_one_item(1);
    items[2] = create_one_item(2);
    items[3] = create_one_item(3);
    items[4] = create_one_item(4);
    items[5] = create_one_item(5);
    items[6] = create_one_item(6);
    items[7] = create_one_item(7);
    items[8] = create_one_item(8);
    items[9] = create_one_item(9);
    items[10] = create_one_item(10);
    items[11] = create_one_item(11);
    items[12] = create_one_item(12);
    items[13] = create_one_item(13);
    items[14] = NULL;
    return (items);
}

item_t **init_items(void)
{
    int nb_id = 14;
    item_t **items = malloc(sizeof(item_t *) * (nb_id + 1));

    if (items == NULL)
        return (NULL);
    items = create_all_items(items);
    for (int count = 0; count < nb_id; count++)
        if (items[count] == NULL)
            return (NULL);
    return (items);
}
