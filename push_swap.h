/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:56 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/25 16:04:43 by ttakino          ###   ########.fr       */
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

void	swap(t_stack *stack, int show_motion);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	push(t_stack *throw, t_stack *catch);
void	rotate(t_stack *stack, int show_motion);
void	rr(t_stack *a, t_stack *b);
void	r_rotate(t_stack *stack, int show_motion);
void	rrr(t_stack *a, t_stack *b);
void	sort_three_nodes(t_stack *a);


long	get_median(t_stack *a, int direction);
void	quick_sort(t_stack *light, t_stack *dark, int group, int pos);

void	input_argvs(t_stack *a, int argc, char **argv);

int	count_stack_size(t_stack *stack, int sign, int direction);


void	__print_stack(t_stack *stack);
 
 #endif