/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:49:20 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 23:52:35 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// finds the node in b that has lowest total cost and moves it to target pos
void	do_best_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	t_stack	*tmp_best;
	int		best_total_cost;

	tmp = *stack_b;
	best_total_cost = INT_MAX;
	while (tmp)
	{
		if (best_total_cost > abs_num(tmp->cost_a) + abs_num(tmp->cost_b))
		{
			best_total_cost = abs_num(tmp->cost_a) + abs_num(tmp->cost_b);
			tmp_best = tmp;
		}
		tmp = tmp->next;
	}
	move_to_a(stack_a, stack_b, tmp_best->cost_a, tmp_best->cost_b);
}

// moves the node in b to target position on a
void	move_to_a(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_ab_to_pos(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_ab_to_pos(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a_to_pos(stack_a, &cost_a);
	rotate_b_to_pos(stack_b, &cost_b);
	push_a(stack_a, stack_b);
}
