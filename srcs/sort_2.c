/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:08:31 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 23:20:25 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// if there are bigger sorted_pos in a, makes target_sorted smallest bigger sorted_pos
// if there aren't makes the target_sorted pos of smallest sorted_pos in stack_a
void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		target_sorted;
	int		target_pos;

	b = *stack_b;
	while (b)
	{
		target_pos = 0;
		target_sorted = INT_MAX;
		a = *stack_a;
		while (a)
		{
			if (a->sorted_pos > b->sorted_pos && a->sorted_pos < target_sorted)
            {
                target_sorted = a->sorted_pos;
			    target_pos = a->pos;
            }
    		a = a->next;
        }
        if (target_sorted != INT_MAX)
		    b->target_pos = target_pos;
        else
        {
            a = *stack_a;
            while (a)
            {
                if (a->sorted_pos < target_sorted)
                {
                    target_sorted = a->sorted_pos;
                    target_pos = a->pos;
                }
                a = a->next;
            }
		    b->target_pos = target_pos ;
        }
        b = b->next;
    }
}

// cost_a is the cost of getting to the right position in stack A.
// cost_b is the cost of getting the element to the top of the B stack
// cost is negative if the node is in the bottom half
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = list_size(tmp_a);
	size_b = list_size(tmp_b);
	while (tmp_b)
	{
		if (tmp_b-> pos -1 <= size_b / 2)
			tmp_b->cost_b = tmp_b->pos - 1;
		else
			tmp_b->cost_b = (size_b - tmp_b->pos +1) * -1;
		if (tmp_b->target_pos -1 <= size_a / 2)
			tmp_b->cost_a = tmp_b->target_pos -1;
		else
			tmp_b->cost_a = (size_a - tmp_b->target_pos +1) * -1;
		tmp_b = tmp_b->next;
	}
}
