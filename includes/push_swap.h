/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:04:14 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/08 08:15:58 by bsengeze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct stack
{
	int	pos;
	int sorted_pos;
	int	val;
	struct stack *next;
}	t_stack;


int main(int ac, char **av);
//list operations

t_stack* create_node(int position, int value);
void add_to_end(t_stack **head, t_stack *new_node);
t_stack *list_tail(t_stack *list);
t_stack *fill_stack_a(int ac, char **av);
int list_size(t_stack *stack);




//error handling functions
void write_error(void);

// util functions
long int	ft_atol(const char *str);
int find_highest(t_stack *stack);
t_stack *new_tail(t_stack *new_tail);


//sort functions
void sorted_pos(t_stack *stack);
int sorted_check(t_stack *stack);
void sort_three(t_stack **stack_a);

//operations
void swap_a(t_stack **stack_a);
void swap_b(t_stack **stack_b);
void swap_ab(t_stack **stack_a, t_stack **stack_b);
void push_a(t_stack **stack_a, t_stack **stack_b);
void push_b(t_stack **stack_a, t_stack **stack_b);
void rotate(t_stack **stack);
void rotate_a(t_stack **stack_a);
void rotate_b(t_stack **stack_a);
void rotate_ab(t_stack **stack_a,t_stack **stack_b);
void reverse_rotate(t_stack **stack);
void reverse_rotate_a(t_stack **stack_a);
void reverse_rotate_b(t_stack **stack_b);
void reverse_rotate_ab(t_stack **stack_a,t_stack **stack_b);



//for_mac
int	ft_isdigit(int c);

#endif
