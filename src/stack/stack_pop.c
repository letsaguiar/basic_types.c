#include "basic-types.h"
#include <stdlib.h>

t_data stack_pop(t_stack *stack)
{
    if (!stack->head)
        return (NULL);

    t_list *head = stack->head;
    t_data data = head->data;

    stack->head = stack->head->next;

    free(head);
    return (data);
}