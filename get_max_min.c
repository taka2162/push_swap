/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_max_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:37:31 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/10 17:19:22 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
