/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/27 17:10:51 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_median_expect(t_stack *stack, int direction)
{
	long	max;
	long	min;
	int		group;

	max = LONG_MIN;
	min = LONG_MAX;
	if (direction == CW)
	{
		stack = stack->next;
		group = stack->next->group;
	}
	else
	{
		stack = stack->prev;
		group = stack->prev->group;
	}
	while (stack->group == group)
	{
		if (stack->data > max)
			max = stack->data;
		if (stack->data < min)
			min = stack->data;
		if (direction == CW)
			stack = stack->next;
		else
			stack = stack->prev;
	}
	return ((max + min) / 2);
}

t_stack	*set_next_node(t_stack *stack, int direction)
{	
	if (direction == CW)
		return (stack->next);
	else
		return (stack->prev);
}

// long	get_min(t_stack *stack, int direction)
// {
// 	long	min;
// 	int		group;
	
// 	min = LONG_MAX;
// 	stack = set_next_node(stack, direction);
// 	group = stack->group;
// 	while (stack->group == group)
// 	{
// 		if (stack->data < min)
// 			min = stack->data;
// 		stack = set_next_node(stack, direction);
// 	}
// 	return (min);
// }

long	get_median(t_stack *stack, int direction)
{
	long	pivot;
	int		len_to_median;
	long	min;
	int		group;
	t_stack	*head;

	head = stack;
	len_to_median = count_stack_size(stack, GROUP, direction) / 2;
	// if (count_stack_size(stack, GROUP, direction) % 2 == 1)
		len_to_median += 1;
	// printf("len_to_median= %d\n", len_to_median);
	group = set_next_node(stack, direction)->group;
	// printf("\x1b[32mgroup = %d  stack->group = %d\n", group, stack->next->group);
	// __print_stack(stack);
	min = LONG_MIN;
	while (0 < len_to_median--)
	{
		stack = set_next_node(head, direction);
		pivot = LONG_MAX;
		while (stack->group == group)
		{
			if (min < stack->data && stack->data < pivot)
				pivot = stack->data;
			stack = set_next_node(stack, direction);
		}
		min = pivot;
	}
	// printf("\x1b[33mpivot = %ld\n\x1b[0m", pivot);
	return (pivot);
}
