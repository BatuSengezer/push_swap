

#include "../includes/push_swap.h"

// Shift down all elements of stack a by 1.
// The last element becomes the first one.
t_stack *new_tail(t_stack *new_tail)
{
    t_stack *old_tail;

    old_tail = new_tail->next;
     while (new_tail && old_tail && old_tail->next)
    {
        new_tail = new_tail->next;
        old_tail = old_tail->next;
    }
    return (new_tail);
}


void reverse_rotate(t_stack **stack)
{
    if (!*stack)
        return ;
    t_stack *tail;
    t_stack *new;
    t_stack *current;
    int pos;
    
   
    tail = list_tail(*stack);
    new = new_tail(*stack);
    tail->next = *stack;
    *stack = tail;
    new->next = NULL;
    pos = 1;
    current = *stack;
    while (current)
    {
        current->pos = pos++;
        current = current->next;
    }
}

void reverse_rotate_a(t_stack **stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}


void reverse_rotate_b(t_stack **stack_b)
{

    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void reverse_rotate_ab(t_stack **stack_a,t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}
