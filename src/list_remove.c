#include "basic-types.h"

void list_remove(t_list **list, int index, void (*destroy)(t_data))
{
    t_list *tmp = list_get(*list, index);
    if (!tmp)
        return;

    if (index == 0)
    {
        *list = tmp->next;
        list_destroy(tmp, destroy);
        return ;
    }

    t_list *prev = list_get(*list, index - 1);
    if (!prev)
        return ;

    prev->next = tmp->next;
    list_destroy(tmp, destroy);
}