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

void sorted_push_except_three(t_stack **stack_a, t_stack **stack_b)
{
    int size;
    int pushed;
    int count;

    size = list_size(*stack_a);
    pushed = 0;
    count = 0;
    while (size > 6 && size > count && size / 2 > pushed)
    {
        if((*stack_a)->sorted_pos <= size/2)
        {
            push_b(stack_a, stack_b);
            pushed++;
            //if ((*stack_a)->next)
        }
        else
            rotate_a(stack_a);
        count++;
    }
    while (size - pushed > 3)
    {
		push_b(stack_a, stack_b);
		pushed++;
    }

}

// add doubles rr rrr ss by comparing stack a b to improve eff


