/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:14:51 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 00:55:24 by bsengeze         ###   ########.fr       */
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

