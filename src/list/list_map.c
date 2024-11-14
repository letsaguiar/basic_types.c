#include "basic-types.h"
#include <stdlib.h>

t_list  *list_map(t_list *list, t_data (*f)(t_data, int))
{
    t_list *head = NULL;
    t_list *tail = NULL;

    int i = 0;
    while (list)
    {
        if (!list_append(&tail, f(list->data, i)))
        {
            list_clear(&head, NULL);
            return (NULL);
        }
        if (!head)
            head = tail;

        list = list->next;
        i += 1;
    }

    return (head);
}