/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:31:10 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 23:32:10 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// // Take the first element at the top of b and put it at the top of a.
// // Do nothing if b is empty.
void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*current_a;
	t_stack	*current_b;
	int		pos;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	current_a = *stack_a;
	current_b = *stack_b;
	pos = 1;
	while (current_a != NULL)
	{
		current_a->pos = pos++;
		current_a = (current_a)->next;
	}
	while (current_b != NULL)
	{
		current_b->pos -= 1;
		current_b = (current_b)->next;
	}
	write(1, "pa\n", 3);
}

// Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*current_a;
	t_stack	*current_b;
	int		pos;

	if (!(*stack_a))
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = *stack_b;
	*stack_b = tmp;
	current_a = *stack_a;
	current_b = *stack_b;
	while (current_a != NULL)
	{
		current_a->pos -= 1;
		current_a = (current_a)->next;
	}
	pos = 1;
	while (current_b != NULL)
	{
		current_b->pos = pos++;
		current_b = (current_b)->next;
	}
	write(1, "pb\n", 3);
}
