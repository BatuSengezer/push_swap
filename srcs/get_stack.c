/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:14:51 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/04 19:07:53 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    while (list)
    {
        if(!list->next)
            return(list);
        list = list->next;
    }
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


t_stack *fill_stack_a(int ac, char **av)
{
    t_stack *stack_a;
    int i;
    long int num;

    stack_a = NULL;
    i = 1;
    num = 0;    
    while (i < ac)
    {
        num = ft_atol(av[i]);
        if (num > INT_MAX || num < INT_MIN)
            write_error();
        else
            add_to_end(&stack_a,create_node(i, (int)num));
        i++;
    }
    sorted_pos(stack_a);
    return (stack_a);
}

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