#include "basic-types.h"

t_list *list_get(t_list *list, int index)
{
    for (int i = 0; list && i < index; i++)
        list = list->next;
    return (list);
}