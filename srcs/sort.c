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



// pushes and partially sorts all elements leaving only three in the stack 
void sorted_push_except_three(t_stack **s_a, t_stack **s_b)
{
    int size;
    int pushed;
    int count;

    size = list_size(*s_a);
    pushed = 0;
    count = 0;
    while (size > 6 && size > count && size / 2 > pushed)
    {
        if(size/2 >= (*s_a)->sorted_pos)
        {
            push_b(s_a, s_b);
            pushed++;
            // if ((*s_a)->next->val < (*s_a)->val && (*s_b)->val < (*s_b)->next->val)  uou can use tmps to reduce column num
            //     ss(s_a, s_b);
            // if ()
            //     rr(s_a, s_b);
            // if ()
            //     rrr(s_a, s_b);
        }
        else
            rotate_a(s_a);
        count++;
    }
    while (size - pushed > 3)
    {
		push_b(s_a, s_b);
		pushed++;
    }

}
// add doubles rr rrr ss by comparinh stack a b and their next
