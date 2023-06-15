/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 22:42:43 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/15 04:07:35 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
int	find_highest(t_stack *stack)
{
	int		highest;
	t_stack	*tmp;

	tmp = stack;
	if (tmp)
		highest = tmp->val;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
		if (tmp->val > highest)
			highest = tmp->val;
	}
	return (highest);
}

int	find_lowest_pos(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp_lowest;

	tmp = *stack;
	if (tmp)
		tmp_lowest = tmp;
	while (tmp)
	{
		if (tmp->sorted_pos < tmp_lowest->sorted_pos)
			tmp_lowest = tmp;
		tmp = tmp->next;
	}
	return (tmp_lowest->pos);
}

// takes absolute of a number
int	abs_num(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}


int	num_str_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}