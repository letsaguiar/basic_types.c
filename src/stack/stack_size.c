#include "basic-types.h"

int stack_size(t_stack *stack)
{
    return list_size(stack->head);
}