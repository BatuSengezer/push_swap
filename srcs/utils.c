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

	highest = stack->val;

	while (stack->next)
	{
		if(stack->val < stack->next->val)
			highest = stack->next->val;
		stack = stack->next;
	}
	return(highest);
}