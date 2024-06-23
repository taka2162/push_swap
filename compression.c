/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/23 17:59:40 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_median(t_stack *stack, int direction)
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
	return ((max + min) / 2);
}
