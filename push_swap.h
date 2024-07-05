/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:56 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/05 15:49:58 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

 #define PUSH_SWAP_H

 #include <unistd.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <limits.h>

 #define TRUE 1
 #define FALSE 0
 #define CW 3
 #define CCW -3
 #define A -1
 #define B -2
 #define STACK 5
 #define GROUP 6
 
typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	long			data;
	int				group;
}	t_stack;

typedef struct s_pos
{
	int a;
	int b;
}	t_pos;

void	swap(t_stack *stack, int show_motion);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	push(t_stack *throw, t_stack *catch);
void	rotate(t_stack *stack, int show_motion);
void	rr(t_stack *a, t_stack *b);
void	r_rotate(t_stack *stack, int show_motion);
void	rrr(t_stack *a, t_stack *b);
void	sort_three_nodes(t_stack *a);

long	get_median_expect(t_stack *stack, int direction);

long	get_min(t_stack *light);
long	get_max(t_stack *light);

t_stack	*set_next_node(t_stack *stack, int direction);

void	insertion_sort(t_stack *light, t_stack *dark, int group);
int		extreme_sort(t_stack *light, t_stack *dark, int group, int direction);
long	get_median(t_stack *stack, int direction);
void	quick_sort(t_stack *light, t_stack *dark, int group);

void	input_argvs(t_stack *a, int argc, char **argv);



int	set_direction(t_stack *light);
int	calculate_direction(t_stack *light, long reference);

int	count_stack_size(t_stack *stack);
int		count_group_size(t_stack *light, int direction);


void	__print_stack(t_stack *stack);
 
 #endif