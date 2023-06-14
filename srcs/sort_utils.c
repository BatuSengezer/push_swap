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

//assings ascending sorted position values to stack starting from 1
void sorted_pos(t_stack *stack)
{
    int size;
    int highest;
    int current_highest;
    t_stack *current;

    size =list_size(stack);
    highest = find_highest(stack);
    while (size > 0)
    {
        current = stack;
        current_highest = INT_MIN;
        while (current)
        {
            if (current->sorted_pos == 0 && current->val == highest)
            {
                current->sorted_pos = size;
                size--;
            }
            if (current->val > current_highest && current->sorted_pos == 0)
                current_highest = current->val;
            current = current->next;
        }
        highest = current_highest;
    }
}