/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_best_move_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:53:09 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 23:54:36 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// reverse rotates both stacks until one of them is in position
void	rev_rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_ab(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

// rotates both stacks until one of them is in position
void	rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_ab(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

// rotates a until it is in position
void	rotate_a_to_pos(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a > 0)
		{
			rotate_a(a);
			(*cost_a)--;
		}
		else if (*cost_a < 0)
		{
			reverse_rotate_a(a);
			(*cost_a)++;
		}
	}
}

// rotates b until it is in position
void	rotate_b_to_pos(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b > 0)
		{
			rotate_b(b);
			(*cost_b)--;
		}
		else if (*cost_b < 0)
		{
			reverse_rotate_b(b);
			(*cost_b)++;
		}
	}
}
