#include "../includes/push_swap.h"

int sorted_check(t_stack *stack)
{
    while (stack->next)
    {
        if(stack->val > stack->next->val)
            return (0);
            stack= stack->next;
    }
    return (1);
}

void sort_three(t_stack **stack_a)
{
    int highest;

    highest = find_highest(*stack_a);
    if (sorted_check(*stack_a) == 1)
        return;
    if ((*stack_a)->val == highest)
    {
        rotate_a(stack_a);
        if (sorted_check(*stack_a) == 0)
        swap_a(stack_a);
    }
    else if((*stack_a)->next->val == highest)
    {
        reverse_rotate_a(stack_a);
        if (sorted_check(*stack_a) == 0)
            swap_a(stack_a);
    }
    else
        swap_a(stack_a);
}
