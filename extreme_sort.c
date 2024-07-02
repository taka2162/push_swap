/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extreme_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:42 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/02 15:50:10 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long	get_min(t_stack *light)
{
	long	min;
	int		group;
	t_stack	*target;
	
	min = LONG_MAX;
	group = set_next_node(light, set_direction(light))->group;
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
	group = set_next_node(light, set_direction(light))->group;
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

long	get_reference(t_stack *light)
{
	if (light->group == A)
		return (get_min(light));
	else
		return (get_max(light));
}

int	push_reference(t_stack *light, t_stack *dark, int group)
{
	int		size;
	long	reference;
	int		direction;

	// direction = CW;
	reference = get_reference(light);
	// printf("reference = %ld\n", reference);
	direction = calculate_direction(light, reference);
	// __print_stack(light);
	size = count_group_size(light, direction);
	// printf("\x1b[34msize = %d\x1b[0m\n", size);
	// printf("direction = %d\n", direction);
	while (0 < size--)
	{
		if (direction == CCW)
			r_rotate(light, TRUE);
		if (light->next->data == reference)
		{
			if (light->group == A)
				light->next->group = group + 1;
			push(light, dark);
			break ;
		}
		else if (direction == CW)
			rotate(light, TRUE);
	}
	return (direction);
}

int	extreme_sort(t_stack *light, t_stack *dark, int group, int direction)
{
	direction = push_reference(light, dark, group);
	if (light->group == A && count_group_size(light, direction) < 3)
	{
		if (light->next->group == light->prev->group)
		{
			if (direction == CW)
				r_rotate(light, TRUE);
			else
				rotate(light, TRUE);
		}
		return (TRUE);
	}
	else if (light->group == B && dark->next->group != light->next->group
		&& dark->next->group != light->prev->group)
		return (FALSE);
	else
		return (extreme_sort(light, dark, group, direction));
}
