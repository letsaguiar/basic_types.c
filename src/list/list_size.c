#include "basic-types.h"

int list_size(t_list *list)
{
    int size = 0;

    while (list)
    {
        size++;
        list = list->next;
    }

    return size;
}