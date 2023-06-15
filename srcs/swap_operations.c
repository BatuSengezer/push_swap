/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:46:51 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 22:51:40 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Swap the first 2 elements at the top of stack a.
// Do nothing if there is only one or no elements
void	swap(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		pos;

	if (!*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	pos = 1;
	current = *stack;
	while (current)
	{
		current->pos = pos++;
		current = current->next;
	}
}

void	swap_a(t_stack **stack_a)
{
	swap(stack_a);
	write(1, "sa\n", 3);
}

// Swap the first 2 elements at the top of stack b.
// Do nothing if there is only one or no elements.
void	swap_b(t_stack **stack_b)
{
	swap(stack_b);
	write(1, "sb\n", 3);
}

// sa and sb at the same time
void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
}
