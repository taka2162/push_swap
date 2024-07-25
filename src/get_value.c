/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:37:31 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:24:47 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

long	get_min(t_stack *light)
{
	long	min;
	int		group;
	t_stack	*target;

	min = LONG_MAX;
	group = set_next_node(light, set_dir(light))->group;
	target = light->next;
	while (target->group == group)
	{
		if (target->data < min)
			min = target->data;
		target = target->next;
	}
	target = light->prev;
	while (target->group == group)
	{
		if (target->data < min)
			min = target->data;
		target = target->prev;
	}
	return (min);
}

long	get_max(t_stack *light)
{
	long	max;
	int		group;
	t_stack	*target;

	max = LONG_MIN;
	group = set_next_node(light, set_dir(light))->group;
	target = light->next;
	while (target->group == group)
	{
		if (max < target->data)
			max = target->data;
		target = target->next;
	}
	target = light->prev;
	while (target->group == group)
	{
		if (max < target->data)
			max = target->data;
		target = target->prev;
	}
	return (max);
}

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
