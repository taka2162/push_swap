/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/26 18:17:41 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_median_expect(t_stack *stack, int direction)
{
	long	max;
	long	min;
	int		group;
	//t_stack	*head;

	max = LONG_MIN;
	min = LONG_MAX;
	if (direction == 0)
	{
		stack = stack->next;
		group = stack->next->group;
	}
	else
	{
		stack = stack->prev;
		group = stack->prev->group;
	}
	//head = stack;
	while (stack->group == group)
	{
		if (stack->data > max)
			max = stack->data;
		if (stack->data < min)
			min = stack->data;
		if (direction == 0)
			stack = stack->next;
		else
			stack = stack->prev;
	}
	// printf("max = %ld  min = %ld   ", max, min);
	return ((max + min) / 2);
}

t_stack	*set_next_node(t_stack *stack, int direction)
{
	t_stack	*first_node;
	
	if (direction == 0)
		first_node = stack->next;
	else
		first_node = stack->prev;
	return (first_node);
}

long	get_min(t_stack *stack, int direction)
{
	long	min;
	int		group;
	
	min = LONG_MAX;
	stack = set_next_node(stack, direction);
	group = stack->group;
	while (stack->group == group)
	{
		if (stack->data < min)
			min = stack->data;
		stack = set_next_node(stack, direction);
	}
	return (min);
}

long	get_median(t_stack *stack, int direction)
{
	long	pivot;
	int		stack_size;
	int		cnt;
	long	dif;
	long	min;
	int		group;
	t_stack	*head;

	min = get_min(stack, direction);
	pivot = min;
	// printf("min = %ld\n", min);
	stack_size = count_stack_size(stack, GROUP, direction);
	// printf("stack_size / 2 - 1= %d\n", stack_size / 2 - 1);
	cnt = 1;
	group = stack->next->group;
	// printf("\x1b[32mgroup = %d  stack->group = %d\n", group, stack->next->group);
	// __print_stack(stack);
	head = stack;
	while (cnt <= (stack_size / 2))
	{
		stack = set_next_node(head, direction);
		// printf("stack =%ld\n", stack->data);
		dif = LONG_MAX;
		while (stack->group == group)
		{
			// printf("dif = %ld\n", dif);
			if (min < stack->data && stack->data - min < dif)
			{
				dif = stack->data - min;
				pivot = stack->data;
			}
			stack = set_next_node(stack, direction);
		}
		min = pivot;
		// printf("\x1b[33mpivot = %ld\n\x1b[0m", pivot);
		cnt++;
		// printf("cnt = %d  stack_size / 2 - 1 = %d\n", cnt, stack_size / 2 - 1);
	}
	return (pivot);
}
