/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsengeze <bsengeze@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:04:14 by bsengeze          #+#    #+#             */
/*   Updated: 2023/06/14 01:28:34 by bsengeze         ###   ########.fr       */
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
	int target_pos;
	int	cost_a;
	int	cost_b;
	struct stack *next;
}	t_stack;


int main(int ac, char **av);

//list operations
t_stack *fill_stack_a(int ac, char **av);
t_stack* create_node(int position, int value);
void add_to_end(t_stack **head, t_stack *new_node);
t_stack *list_tail(t_stack *list);
int list_size(t_stack *stack);
void free_list(t_stack **list);




//error handling functions
void write_error(void);

// util functions
long int ft_atol(const char *str);
int find_highest(t_stack *stack);
int find_lowest_pos(t_stack **stack);
int abs_num(int num);
t_stack *new_tail(t_stack *new_tail);


//sort functions
void sorted_pos(t_stack *stack);
int sorted_check(t_stack *stack);
void sort_three(t_stack **stack_a);
void sorted_push_except_three(t_stack **stack_a, t_stack **stack_b);
void sort_big(t_stack **stack_a, t_stack **stack_b);
void get_target_pos(t_stack **stack_a, t_stack **stack_b);
void get_cost(t_stack **stack_a, t_stack **stack_b);
void do_best_move(t_stack **stack_a, t_stack **stack_b);
void move_to_a(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b);
void rev_rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void rotate_ab_to_pos(t_stack **a, t_stack **b, int *cost_a, int *cost_b);
void rotate_a_to_pos(t_stack **a, int *cost_a);
void rotate_b_to_pos(t_stack **b, int *cost_b);
void shift_stack(t_stack **stack_a);
void push_swap(t_stack **stack_a, t_stack **stack_b);



//operations
void swap(t_stack **stack);
void swap_a(t_stack **stack_a);
void swap_b(t_stack **stack_b);
void swap_ab(t_stack **stack_a, t_stack **stack_b);
void push_a(t_stack **stack_a, t_stack **stack_b);
void push_b(t_stack **stack_a, t_stack **stack_b);
void rotate(t_stack **stack);
void rotate_a(t_stack **stack_a);
void rotate_b(t_stack **stack_b);
void rotate_ab(t_stack **stack_a,t_stack **stack_b);
void reverse_rotate(t_stack **stack);
void reverse_rotate_a(t_stack **stack_a);
void reverse_rotate_b(t_stack **stack_b);
void reverse_rotate_ab(t_stack **stack_a,t_stack **stack_b);



//for_mac
int	ft_isdigit(int c);

#endif
