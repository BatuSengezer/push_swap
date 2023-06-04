#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements
void swap_a(t_stack **stack_a)
{
    t_stack *tmp;

    if(!*stack_a || !(*stack_a)->next)
        return ;
    tmp->val = (*stack_a)->val;
    (*stack_a)->val = (*stack_a)->next->val;
    (*stack_a)->next->val = tmp->val;
    tmp->sorted_pos = (*stack_a)->sorted_pos;
    (*stack_a)->sorted_pos = (*stack_a)->next->sorted_pos;
    (*stack_a)->next->sorted_pos = tmp->sorted_pos;
    write(1, "sa\n", 3);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void swap_b(t_stack **stack_b)
{
    t_stack *tmp;

    if(!*stack_b || !(*stack_b)->next)
        return ;
    tmp->val = (*stack_b)->val;
    (*stack_b)->val = (*stack_b)->next->val;
    (*stack_b)->next->val = tmp->val;
    tmp->sorted_pos = (*stack_b)->sorted_pos;
    (*stack_b)->sorted_pos = (*stack_b)->next->sorted_pos;
    (*stack_b)->next->sorted_pos = tmp->sorted_pos;
    write(1, "sb\n", 3);
}

// sa and sb at the same time
void swap_ab(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

    if(!*stack_a || !(*stack_a)->next || !*stack_b || !(*stack_b)->next)
        return ;
    tmp_a->val = (*stack_a)->val;
    (*stack_a)->val = (*stack_a)->next->val;
    (*stack_a)->next->val = tmp_a->val;
    tmp_a->sorted_pos = (*stack_a)->sorted_pos;
    (*stack_a)->sorted_pos = (*stack_a)->next->sorted_pos;
    (*stack_a)->next->sorted_pos = tmp_a->sorted_pos;
    tmp_b->val = (*stack_b)->val;
    (*stack_b)->val = (*stack_b)->next->val;
    (*stack_b)->next->val = tmp_b->val;
    tmp_b->sorted_pos = (*stack_b)->sorted_pos;
    (*stack_b)->sorted_pos = (*stack_b)->next->sorted_pos;
    (*stack_b)->next->sorted_pos = tmp_b->sorted_pos;
    write(1, "ss\n", 3);
}


