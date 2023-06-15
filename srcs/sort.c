/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:52:39 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 23:03:04 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	highest;

	if (sorted_check(*stack_a) == 1)
		return ;
	highest = find_highest(*stack_a);
	if ((*stack_a)->val == highest)
	{
		rotate_a(stack_a);
		if (sorted_check(*stack_a) == 0)
			swap_a(stack_a);
	}
	else if ((*stack_a)->next->val == highest)
	{
		reverse_rotate_a(stack_a);
		if (sorted_check(*stack_a) == 0)
			swap_a(stack_a);
	}
	else
		swap_a(stack_a);
}

// pushes and partially sorts all elements leaving only three in the stack 
void	sorted_push_except_three(t_stack **s_a, t_stack **s_b)
{
	int	size;
	int	pushed;
	int	count;

	size = list_size(*s_a);
	pushed = 0;
	count = 0;
	while (size > 6 && size > count && size / 2 > pushed)
	{
		if (size / 2 >= (*s_a)->sorted_pos)
		{
			push_b(s_a, s_b);
			pushed++;
		}
		else
			rotate_a(s_a);
		count++;
	}
	while (size - pushed > 3)
	{
		push_b(s_a, s_b);
		pushed++;
	}
}

// add doubles rr rrr ss by comparinh stack a b and their next
void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	sorted_push_except_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_best_move(stack_a, stack_b);
	}
	if (!sorted_check(*stack_a))
		shift_stack(stack_a);
}

// shifts stack a until the lowest value is at the top. 
void	shift_stack(t_stack **stack_a)
{
	int	lowest;
	int	size;

	size = list_size(*stack_a);
	lowest = find_lowest_pos(stack_a) -1;
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			reverse_rotate_a(stack_a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			rotate_a(stack_a);
			lowest--;
		}
	}
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = list_size(*stack_a);
	if (size == 2 && !sorted_check(*stack_a))
		swap_a(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size > 3 && !sorted_check(*stack_a))
		sort_big(stack_a, stack_b);
}
