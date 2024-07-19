/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/19 15:42:33 by ttakino          ###   ########.fr       */
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
		rotate(light, TRUE);
	while (pos.a < 0 && pos.a++ < 0)
		r_rotate(light, TRUE);
	while (0 < pos.b && 0 < pos.b--)
		rotate(dark, TRUE);
	while (pos.b < 0 && pos.b++ < 0)
		r_rotate(dark, TRUE);
	push(light, dark);
}

void	push_to_a(t_stack *light, t_stack *dark, int group)
{
	// int		group;
	int		count;
	long	max;
	t_stack	*target;

	// group = set_next_node(dark, set_dir(dark))->group;
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
	while (dark->next->group == group || light->prev->data < light->next->data)
	{
		// if (light->prev->data < light->next->data && light->prev->data > dark->next->data)
		// {
		// 	// __print_stack(light);
		// 	// __print_stack(dark);	
		// 	r_rotate(light, TRUE);
		// 	continue ;
		// }
		push(dark, light);
	}
	// printf("dark->next->data = %ld\n", dark->next->data);
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

void	sort_three_sort_group(t_stack *stack)
{
	long	first;
	long	second;
	long	third;

	first = stack->next->data;
	second = stack->next->next->data;
	third = stack->next->next->next->data;
	if (first > second && second > third)
	{
		swap(stack, TRUE);
		r_rotate(stack, TRUE);
	}
	else if (first > second && third > second && first > third)
		rotate(stack, TRUE);
	else if (first > second && third > second && third > first)
		swap(stack, TRUE);
	else if (second > first && second > third && first > third)
		r_rotate(stack, TRUE);
	else if (second > first && second > third && third > first)
	{
		r_rotate(stack, TRUE);
		swap(stack, TRUE);
	}
}

void	insertion_sort(t_stack *light, t_stack *dark, int group)
{
	t_pos	pos;
	int		dir;
	int		dark_group;

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
		push_to_b(light, dark, pos);
		// if (count_group_size(light, dir) <= 2)
		// 	break ;
	}
	sort_one_or_two(light, dark, count_group_size(light, dir), dir);
	// printf("---after sort_one_or_two  \n  ");
	// __print_stack(light);
	// __print_stack(dark);
	dark_group = set_next_node(dark, dir)->group;
	push_to_a(light, dark, dark_group);
	// printf("---after push_to_a  \n  ");
	// __print_stack(light);
	// __print_stack(dark);
}
