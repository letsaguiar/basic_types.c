#include "basic-types.h"
#include <stdlib.h>

t_stack *stack_create()
{
    t_stack *stack = malloc(sizeof(t_stack));
    stack->head = NULL;

    return (stack);
}