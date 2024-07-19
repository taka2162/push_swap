/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:56 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/19 15:06:37 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define TRUE 1
# define FALSE 0
# define CW 3
# define CCW -3
# define A -1
# define B -2
# define STACK 5
# define GROUP 6

typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	long			data;
	int				group;
}	t_stack;

typedef struct s_pos
{
	int	a;
	int	b;
}	t_pos;

void	input_argvs(t_stack *a, int argc, char **argv);
void	input_arglist(t_stack *a, long *arg_list);
int		is_error(int argc, t_stack *a, char **argv);

void	initialize_stack(t_stack *a, t_stack *b);
void	clear_stack(t_stack *stack);

void	swap(t_stack *stack, int show_motion);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	push(t_stack *throw, t_stack *catch);
void	rotate(t_stack *stack, int show_motion);
void	rr(t_stack *a, t_stack *b);
void	r_rotate(t_stack *stack, int show_motion);
void	rrr(t_stack *a, t_stack *b);

int		count_stack_size(t_stack *stack);
int		count_group_size(t_stack *light, int dir);

void	sort_one_or_two(t_stack *light, t_stack *dark, int size, int dir);
void	sort_three_nodes(t_stack *a);

long	get_median(t_stack *stack, int dir);

t_stack	*set_next_node(t_stack *stack, int dir);

long	get_min(t_stack *light);
long	get_max(t_stack *light);

t_pos	choose_best_node(t_stack *light, t_stack *dark, int mark, int dir);
void	insertion_sort(t_stack *light, t_stack *dark, int group);

int		extreme_sort(t_stack *light, t_stack *dark, int group, int dir);

int		set_dir(t_stack *light);
void	quick_sort(t_stack *light, t_stack *dark, int group);

void	__print_stack(t_stack *stack);

#endif
