/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/23 14:49:53 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_stack *light, t_stack *dark, t_pos pos)
{
	while (0 < pos.a && 0 < pos.b && 0 < (pos.a--) * (pos.b--))
		rr(light, dark);
	while (pos.a < 0 && pos.b < 0 && 0 < (pos.a++) * (pos.b++))
		rrr(light, dark);
	while (0 < pos.a && 0 < pos.a--)
		rotate(light, true);
	while (pos.a < 0 && pos.a++ < 0)
		r_rotate(light, true);
	while (0 < pos.b && 0 < pos.b--)
		rotate(dark, true);
	while (pos.b < 0 && pos.b++ < 0)
		r_rotate(dark, true);
	push(light, dark);
}

void	to_descending_form(t_stack *dark, int group)
{
	int		cnt;
	long	max;
	t_stack	*target;

	max = get_max(dark);
	cnt = 0;
	target = dark->next;
	while (target->data != max)
	{
		cnt++;
		target = target->next;
	}
	while (dark->prev->data > dark->next->data && dark->prev->group == group)
	{
		if (count_stack_size(dark) / 2 < cnt)
			r_rotate(dark, true);
		else
			rotate(dark, true);
	}
}

void	push_to_a(t_stack *light, t_stack *dark, int darkgroup, bool is_only)
{
	int	cnt;
	int	group;

	group = darkgroup;
	group = dark->next->group;
	to_descending_form(dark, group);
	cnt = 3;
	while (dark->next->group == group || light->prev->data < light->next->data)
	{
		if (is_only && dark->next->data < light->prev->data && 0 < cnt)
		{
			r_rotate(light, true);
			cnt--;
			continue ;
		}
		if (count_stack_size(dark) == 0)
			break ;
		push(dark, light);
	}
	while (is_only && 0 < cnt--)
		r_rotate(light, true);
}

void	set_for_insertion_form(t_stack *light, t_stack *dark, int group)
{
	t_stack	*target;
	int		original;
	int		dir;

	dir = set_dir(light);
	target = set_next_node(light, dir);
	original = target->group;
	while (target->group == original)
	{
		target->group = group + 1;
		target = set_next_node(target, dir);
	}
	if (dir == CCW)
	{
		r_rotate(light, true);
		r_rotate(light, true);
	}
	push(light, dark);
	if (3 < count_stack_size(light))
		push(light, dark);
	if (dark->next->data < dark->next->next->data)
		swap(dark, true);
}

void	insertion_sort(t_stack *light, t_stack *dark, int group, bool is_only)
{
	t_pos	pos;
	int		dir;
	int		dark_group;

	dir = set_dir(light);
	set_for_insertion_form(light, dark, group);
	while (light->next->group == group + 1 || light->prev->group == group + 1)
	{
		if (is_only && count_stack_size(light) <= 3)
			break ;
		pos = choose_best_node(light, dark, 0, CW);
		push_to_b(light, dark, pos);
	}
	if (is_only && count_stack_size(light) <= 3)
		sort_three_nodes(light);
	dark_group = set_next_node(dark, dir)->group;
	push_to_a(light, dark, dark_group, is_only);
}
