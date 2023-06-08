#include "../includes/push_swap.h"

//allocate memory and create a new node with given position and value
t_stack* create_node(int position, int value)
{
    t_stack *new_node;

    new_node = (t_stack*)malloc(sizeof(t_stack));
    if (!new_node)
        return (NULL);
    new_node->pos = position;
    new_node->val = value;
    new_node->sorted_pos = 0;
    new_node->next = NULL;
    return (new_node);
}

//takes head as input and returns a pointer to the tail of the list
t_stack *list_tail(t_stack *list)
{
    while (list && list->next)
        list = list->next;
    return(list);
}

//add node to the end of the list
void add_to_end(t_stack **head, t_stack *new_node)
{
    if (!head)
        return;
    // if there is no head, makes a head node
    if (!(*head))
        *head = new_node;
    else
        list_tail(*head)->next = new_node;
}

int list_size(t_stack *stack)
{
    int size;

    size = 0;
    while(stack)
    {
        size++;
        if(!stack->next)
            return(size);
        stack = stack->next;
    }
    return(size);
}
