#include "basic-types.h"

int stack_size(t_stack *stack)
{
    if (!stack)
        return (0);

    return list_size(stack->head);
}