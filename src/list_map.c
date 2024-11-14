#include "basic-types.h"
#include <stdlib.h>

t_list  *list_map(t_list *list, t_data (*f)(t_data))
{
    t_list *head = NULL;
    t_list *tail = NULL;

    while (list)
    {
        if (!list_append(&tail, f(list->data)))
        {
            list_clear(&head, NULL);
            return (NULL);
        }
        if (!head)
            head = tail;
        list = list->next;
    }

    return (head);
}