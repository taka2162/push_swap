/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/10 17:19:22 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_best_node(t_stack *light, t_stack *dark, t_pos pos)
{
	while (0 < pos.a && 0 < pos.b && 0 < pos.a-- * pos.b--)
		rr(light, dark);
	while (pos.a < 0 && pos.b < 0 && 0 < pos.a++ * pos.b++)
		rrr(light, dark);
	while (0 < pos.a && 0 < pos.a--)
		rotate(light, TRUE);
	while (pos.a < 0 && pos.a++ < 0)
		r_rotate(light, TRUE);
	while (0 < pos.b && 0 < pos.b--)
		rotate(dark, TRUE);
	while (pos.b < 0 && pos.b++ < 0)
		r_rotate(dark, TRUE);
	push(light, dark);
}

void	push_to_a(t_stack *light, t_stack *dark)
{
	int		group;
	int		count;
	long	max;
	t_stack	*target;

	group = set_next_node(dark, set_dir(dark))->group;
	max = get_max(dark);
	target = dark->next;
	count = 0;
	while (target->data != max)
	{
		count++;
		target = target->next;
	}
	while (dark->prev->data > dark->next->data && dark->prev->group == group)
	{
		if (count_stack_size(dark) / 2 < count)
			r_rotate(dark, TRUE);
		else
			rotate(dark, TRUE);
	}
	while (dark->next->group == group)
		push(dark, light);
}

void	initialize_group(t_stack *light, int group, int dir)
{
	t_stack	*target;
	int		original;
	
	target = set_next_node(light, dir);
	original = target->group;
	while (target->group == original)
	{
		target->group = group + 1;
		target = set_next_node(target, dir);
	}
}

void	insertion_sort(t_stack *light, t_stack *dark, int group)
{
	t_pos	pos;
	int		dir;

	dir = set_dir(light);
	initialize_group(light, group, dir);
	if (dir == CCW)
	{
		r_rotate(light, TRUE);
		r_rotate(light, TRUE);
	}
	push(light, dark);
	push(light, dark);
	if (dark->next->data < dark->next->next->data)
		swap(dark, TRUE);
	while (light->next->group == group + 1 || light->prev->group == group + 1)
	{
		pos = choose_best_node(light, dark, 0, CW);
		push_best_node(light, dark, pos);
	}
	push_to_a(light, dark);
}