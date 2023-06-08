/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:14:51 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/08 03:37:38 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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