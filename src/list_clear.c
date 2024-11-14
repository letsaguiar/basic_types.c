#include "basic-types.h"

void    list_clear(t_list **list, void (*destroy)(t_data))
{
    t_list  *tmp;

    while (*list)
    {
        tmp = *list;
        *list = (*list)->next;
        list_destroy(tmp, destroy);
    }
}