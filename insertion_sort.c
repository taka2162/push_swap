/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:42 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/01 18:07:09 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


long	get_min(t_stack *light, int direction)
{
	long	min;
	int		group;
	t_stack	*target;
	
	min = LONG_MAX;
	group = set_next_node(light, direction)->group;
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

long	get_max(t_stack *light, int direction)
{
	long	max;
	int		group;
	t_stack	*target;

	max = LONG_MIN;
	group = set_next_node(light, direction)->group;
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

long	get_reference(t_stack *light, int direction)
{
	if (light->group == A)
		return (get_min(light, direction));
	else
		return (get_max(light, direction));
}

int	set_next_direction(t_stack *light, int direction)
{
	if (light->next->group > light->prev->group)
		return (CW);
	else if (light->next->group == light->prev->group)
		return (direction);
	else
		return (CCW);
}

int	calculate_direction(t_stack *light, long reference, int direction)
{
	t_stack	*target;
	int		cnt;
	int		size;

	size = count_stack_size(light, STACK, direction) / 2 + 1;
	target = light->next;
	cnt = 0;
	while (target->group != light->group)
	{
		cnt++;
		if (target->data == reference)
			break;
		target = target->next;
	}
	if (cnt < size)
		return (CW);
	else
		return (CCW);
}

int	count_group_size(t_stack *light, int direction)
{
	int		count;
	t_stack	*target;
	int		group;

	count = 0;
	target = light->next;
	group = set_next_node(light, direction)->group;
	while (target->group == group)
	{
		count++;
		target = target->next;
		if (target->group == light->group)
			return (count);
	}
	target = light->prev;
	while (target->group == group)
	{
		count++;
		target = target->prev;
	}
	return (count);
}

void	sort_light_group(t_stack *light, t_stack *dark, int group, int direction)
{
	int		size;
	long	reference;

	// printf("direction = %d\n", direction);
	size = count_group_size(light, direction);
	// printf("\x1b[34msize = %d\x1b[0m\n", size);
	reference = get_reference(light, direction);
	// printf("reference = %ld\n", reference);
	direction = calculate_direction(light, reference, direction);
	// __print_stack(light);
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
}

int	insertion_sort(t_stack *light, t_stack *dark, int group, int direction)
{
	sort_light_group(light, dark, group, direction);
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
		return (insertion_sort(light, dark, group, set_next_direction(light, direction)));
}
