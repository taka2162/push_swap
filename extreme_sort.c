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

long	get_reference(t_stack *light)
{
	if (light->group == A)
		return (get_min(light));
	else
		return (get_max(light));
}

int	calculate_dir(t_stack *light, long reference)
{
	t_stack	*target;
	int		cnt;
	int		size;

	size = count_stack_size(light) / 2 + 1;
	target = light->next;
	cnt = 0;
	while (target->group != light->group)
	{
		cnt++;
		if (target->data == reference)
			break ;
		target = target->next;
	}
	if (cnt < size)
		return (CW);
	else
		return (CCW);
}

int	push_reference(t_stack *light, t_stack *dark, int group)
{
	int		size;
	long	reference;
	int		dir;

	reference = get_reference(light);
	dir = calculate_dir(light, reference);
	size = count_group_size(light, dir);
	while (0 < size--)
	{
		if (dir == CCW)
			r_rotate(light, true);
		if (light->next->data == reference)
		{
			if (light->group == A)
				light->next->group = group + 1;
			push(light, dark);
			break ;
		}
		else if (dir == CW)
			rotate(light, true);
	}
	return (dir);
}

bool	extreme_sort(t_stack *light, t_stack *dark, int group, int dir)
{
	dir = push_reference(light, dark, group);
	if (light->group == A && count_group_size(light, dir) < 3)
	{
		if (light->next->group == light->prev->group)
		{
			if (dir == CW)
				r_rotate(light, true);
			else
				rotate(light, true);
		}
		return (true);
	}
	else if (light->group == B && dark->next->group != light->next->group
		&& dark->next->group != light->prev->group)
		return (false);
	else
		return (extreme_sort(light, dark, group, dir));
}
