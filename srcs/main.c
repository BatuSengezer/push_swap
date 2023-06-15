/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:32:53 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/15 05:27:13 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av)) 
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack_a(ac, av);
	push_swap(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
