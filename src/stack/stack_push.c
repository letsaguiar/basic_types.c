#include "basic-types.h"

int stack_push(t_stack *stack, t_data data, void (*destroy)(t_data))
{
    if (!stack)
        return (0);

    return (list_insert(&stack->head, data, 0, destroy));
}