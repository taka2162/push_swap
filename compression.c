/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:55:20 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_median(t_stack *stack)
{
	long	max;
	long	min;
	int		group;
	//t_stack	*head;

	max = LONG_MIN;
	min = LONG_MAX;
	group = stack->next->group;
	//head = stack;
	stack = stack->next;
	while (stack->group == group)
	{
		if (stack->data > max)
			max = stack->data;
		if (stack->data < min)
			min = stack->data;
		stack = stack->next;
	}
	return ((max + min) / 2);
}
