
#include "../includes/push_swap.h"

// Shift up all elements of stack a by 1.
// The first element becomes the last one.
void rotate(t_stack **stack)
{
    if (!*stack)
        return ;
    t_stack *head;
    t_stack *current;
    t_stack *tail;

    tail = list_tail(*stack);
    head = *stack;
    *stack = (*stack)->next;
    head->next = NULL;
    tail->next = head;

    current = *stack;
    while (current)
    {
        (current)->pos -= 1;
        current = current->next;
    }
    list_tail(*stack)->pos = list_size(*stack);
}

void rotate_a(t_stack **stack_a)
{
    rotate(stack_a);
    write(1, "ra\n", 3);
}


void rotate_b(t_stack **stack_b)
{
    rotate(stack_b);
    write(1, "rb\n", 3);
}


void rotate_ab(t_stack **stack_a,t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    write(1, "rr\n", 3);
}
