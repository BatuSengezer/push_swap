
#include "../includes/push_swap.h"

// if there are bigger sorted_pos in a, makes target smallest bigger sorted_pos
// if there aren't makes the target pos of smallest sorted_pos in stack_a
void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
    int target_sorted_pos;
    int target_pos;

	b = *stack_b;
    while (b)
    {
        target_pos = 0;
        target_sorted_pos = INT_MAX;
        a = *stack_a;
        while (a)
        {
            if (a->sorted_pos > b->sorted_pos && a->sorted_pos < target_sorted_pos)
            {
                target_sorted_pos = a->sorted_pos;
			    target_pos = a->pos;
            }
    		a = a->next;
        }
        if (target_sorted_pos != INT_MAX)
		    b->target_pos = target_pos;
        else
        {
            a = *stack_a;
            while (a)
            {
                if (a->sorted_pos < target_sorted_pos)
                {
                    target_sorted_pos = a->sorted_pos;
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
        if (tmp_b->pos -1 <= size_b / 2)
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
void move_to_a(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_ab_to_pos(stack_a, stack_b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_ab_to_pos(stack_a, stack_b, &cost_a, &cost_b);
	rotate_a_to_pos(stack_a, &cost_a);
	rotate_b_to_pos(stack_b, &cost_b);
	push_a(stack_a, stack_b);
}

// reverse rotates both stacks until one of them is in position
void rev_rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
    while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_ab(a, b);
        (*cost_a)++;
		(*cost_b)++;
	}
}

// rotates both stacks until one of them is in position
void rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
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
