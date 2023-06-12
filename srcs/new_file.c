
#include "../includes/push_swap.h"


// void	target_position(t_stack **stack_a, t_stack **stack_b)
// {
//     t_stack	*tmp;
// 	int	target_pos;

//     target_pos = 0;
//     tmp = *stack_b;
//     while(tmp)
//     {

//     }
// }


void	get_target(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
    int target_sorted_pos;
    int target_pos;

    a = *stack_a;
	b = *stack_b;
    target_pos = 0;
    target_sorted_pos = INT_MAX;
    while (b)
    {
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
        target_sorted_pos = INT_MAX;
        a = *stack_a;
        b = b->next;
    }
}


// /* get_target:
// *	Picks the best target position in stack A for the given index of
// *	an element in stack B. First checks if the index of the B element can
// *	be placed somewhere in between elements in stack A, by checking whether
// *	there is an element in stack A with a bigger index. If not, it finds the
// *	element with the smallest index in A and assigns that as the target position
// */
// static int	get_target(t_stack **a, int b_idx,
// 								int target_idx, int target_pos)
// {
// 	t_stack	*tmp_a;

// 	tmp_a = *a;
// 	while (tmp_a)
// 	{
// 		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
// 		{
// 			target_idx = tmp_a->index;
// 			target_pos = tmp_a->pos;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	if (target_idx != INT_MAX)
// 		return (target_pos);
// 	tmp_a = *a;
// 	while (tmp_a)
// 	{
// 		if (tmp_a->index < target_idx)
// 		{
// 			target_idx = tmp_a->index;
// 			target_pos = tmp_a->pos;
// 		}
// 		tmp_a = tmp_a->next;
// 	}
// 	return (target_pos);
// }



// /* get_target_position:
// *	Assigns a target position in stack A to each element of stack A.
// *	The target position is the spot the element in B needs to
// *	get to in order to be sorted correctly. This position will
// *	be used to calculate the cost of moving each element to
// *	its target position in stack A.
// */
// void	get_target_position(t_stack **a, t_stack **b)
// {
// 	t_stack	*tmp_b;
// 	int		target_pos;

// 	tmp_b = *b;
// 	get_position(a);
// 	get_position(b);
// 	target_pos = 0;
// 	while (tmp_b)
// 	{
// 		target_pos = get_target(a, tmp_b->index, INT_MAX, target_pos);
// 		tmp_b->target_pos = target_pos;
// 		tmp_b = tmp_b->next;
// 	}
// }
