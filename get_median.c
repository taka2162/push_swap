/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/10 17:16:40 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static long	get_median_expect(t_stack *stack, int dir)
// {
// 	long	max;
// 	long	min;
// 	int		group;

// 	max = LONG_MIN;
// 	min = LONG_MAX;

// 	stack = set_next_node(stack, dir);
// 	group = stack->group;
// 	while (stack->group == group)
// 	{
// 		if (stack->data > max)
// 			max = stack->data;
// 		if (stack->data < min)
// 			min = stack->data;
// 		if (dir == CW)
// 			stack = stack->next;
// 		else
// 			stack = stack->prev;
// 	}
// 	return ((max + min) / 2);
// }

long	get_median(t_stack *stack, int dir)
{
	long	pivot;
	int		len_to_median;
	long	min;
	int		group;
	t_stack	*head;

	head = stack;
	len_to_median = count_group_size(stack, dir) / 2 + 1;
	group = set_next_node(stack, dir)->group;
	min = LONG_MIN;
	while (0 < len_to_median--)
	{
		stack = set_next_node(head, dir);
		pivot = LONG_MAX;
		while (stack->group == group)
		{
			if (min < stack->data && stack->data < pivot)
				pivot = stack->data;
			stack = set_next_node(stack, dir);
		}
		min = pivot;
	}
	return (pivot);
}
