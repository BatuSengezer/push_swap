#include "../includes/push_swap.h"

// long int atoi to secure conversion of input values that exceeds int limits
long int	ft_atol(const char *str)
{
	long int	nb;
	int			isneg;
	int			i;

	nb = 0;
	isneg = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	return (nb * isneg);
}

//finds highest int in the list
int find_highest(t_stack *stack)
{
	int highest;
	t_stack *tmp;

	tmp = stack;
	if (tmp)
		highest = tmp->val;

	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if(tmp->val > highest)
			highest = tmp->val;
	}
	return(highest);
}

int find_lowest_pos(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tmp_lowest;

	tmp = *stack;
	if (tmp)
		tmp_lowest = tmp;
	while (tmp)
	{
		if(tmp->sorted_pos < tmp_lowest->sorted_pos)
			tmp_lowest = tmp;
		tmp = tmp->next;
	}
	return(tmp_lowest->pos);
}

// takes absolute of a number
int abs_num(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

