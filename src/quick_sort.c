/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:22:00 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_to_dark(t_stack **light, t_stack *dark, int group, int dir)
{
	set_next_node(*light, dir)->group = group + 1;
	if (dir == CCW)
		r_rotate(*light, true);
	push(*light, dark);
}

static void	divide_group(t_stack *light, t_stack *dark, int group, int dir)
{
	t_stack	*target;
	long	median;
	int		size;

	target = set_next_node(light, dir);
	median = get_median(light, dir);
	size = count_group_size(light, dir);
	while (size-- > 0)
	{
		if (target->data < median && light->group == A)
			push_to_dark(&light, dark, group, dir);
		else if (target->data >= median && light->group == B)
			push_to_dark(&light, dark, group, dir);
		else
		{
			if (dir == CW)
				rotate(light, true);
			else
				r_rotate(light, true);
		}
		target = set_next_node(light, dir);
	}
}

static void	sort_one_or_two(t_stack *light, t_stack *dark, int size, int dir)
{
	if (dir == CCW)
	{
		r_rotate(light, true);
		if (size >= 2)
			r_rotate(light, true);
	}
	if (light->group == A && size == 2
		&& light->next->data > light->next->next->data)
		swap(light, true);
	else if (light->group == B)
	{
		if (light->next->data < light->next->next->data && size == 2)
			swap(light, true);
		push(light, dark);
		if (2 <= size)
			push(light, dark);
	}
}

static bool	sorting_method(t_stack *light, t_stack *dark, int *group, int dir)
{
	bool	flag;
	int		size;

	flag = false;
	size = count_group_size(light, dir);
	if (size <= 2)
		sort_one_or_two(light, dark, size, dir);
	else if (size <= 9)
		flag = extreme_sort(light, dark, *group, dir);
	else if (size <= 365 && light->group == A)
	{
		insertion_sort(light, dark, *group, false);
		(*group)++;
	}
	else
	{
		divide_group(light, dark, *group, dir);
		flag = true;
	}
	return (flag);
}

void	quick_sort(t_stack *light, t_stack *dark, int group)
{
	int		dir;
	bool	flag;

	dir = set_dir(light);
	flag = sorting_method(light, dark, &group, dir);
	if (light->next == light || dark->next == dark)
		return ;
	if (light->group == A)
	{
		if (flag)
			quick_sort(light, dark, group + 1);
		else
			quick_sort(dark, light, group);
	}
	else if (light->group == B)
	{
		if (flag)
			quick_sort(dark, light, group + 1);
		else
			quick_sort(light, dark, group);
	}
}
