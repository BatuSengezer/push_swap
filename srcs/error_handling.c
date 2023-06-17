/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:09 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/16 17:39:26 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	num_check(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]) && av[i + 1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && !ft_isdigit(av[i]))
		return (0);
	return (1);
}

int	zero_check(char *av)
{
	int	i;

	i = 0;
	if (ft_issign(av[i]))
		i++;
	while (av[i] && av[i] == '0')
		i++;
	if (av[i] != '\0')
		return (0);
	return (1);
}

int	duplicate_check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 1;
		while (av[j])
		{
			if (j != i && num_str_cmp(av[i], av[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_correct_input(char **av)
{
	int	i;
	int	zeros_cnt;

	zeros_cnt = 0;
	i = 1;
	while (av[i])
	{
		if (!num_check(av[i]))
			return (0);
		zeros_cnt += zero_check(av[i]);
		i++;
	}
	if (zeros_cnt > 1)
		return (0);
	if (duplicate_check(av))
		return (0);
	return (1);
}

void	write_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
