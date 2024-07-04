/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/04 18:18:40 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	calculate_best_position(t_stack *dark, long value)
{
	int		pos;
	int		direction;
	int		num;
	t_stack	*target;

	pos = 0;
	// if (dark->next->group == dark->prev->group && value < dark->prev->data)
	// {
	// 	direction = CW;
	// 	num = 1;
	// }
	if (dark->next->group == dark->prev->group && value > dark->next->data)
	{
		direction = CCW;
		num = -1;
	}
	else
	{
		direction = CW;
		num = 1;
	}
	target = set_next_node(dark, direction);
	// printf("\x1b[33m");
	// printf("direction = %d  num = %d\n", direction, num);
	// printf("b->group = %d  dark->next->group = %d\n", target->group, dark->next->group);
	while (target->group == dark->next->group)
	{
		// printf("---%d * (%ld - %ld) = %ld---\n", 
		// 	num, value, target->data,
		// 		 num * (value - target->data));
		if (0 < num * (value - target->data))
			break ;
		pos++;
		target = set_next_node(target, direction);
		//printf("target = %ld\n", target->data);
	}
	pos *= (direction / 3);
	// printf("pos = %d\n", pos);
	// printf("\x1b[0m");
	return (pos);
}

t_pos	calculate_best_node(t_stack *light, t_stack *dark, int group)
{
	int		min;
	int		pos_b;
	int		i;
	t_pos	pos;
	t_stack	*target;

	// __print_stack(light);
	// __print_stack(dark);
	min = INT_MAX;
	i = 0;
	pos_b = 0;
	target = light->next;
	while (target->group == group)
	{
		pos_b = calculate_best_position(dark, target->data);
		if (abs(pos_b) + i < min)
		{
			min = abs(pos_b) + i;
			pos.a = i;
			pos.b = pos_b;
		}
		i++;
		target = target->next;
	}
	i = 1;
	target = light->prev;
	while (target->group == group)
	{
		pos_b = calculate_best_position(dark, target->data);
		if (abs(pos_b) + i < min)
		{
			min = abs(pos_b) + i;
			pos.a = i * -1;
			pos.b = pos_b;
		}
		i++;
		target = target->prev;
	}
	// printf("pos.a = %d  pos.b = %d\n", pos.a, pos.b);
	return (pos);
}

void	push_best_node(t_stack *light, t_stack *dark, t_pos pos)
{
	int	direction;

	if (0 <= pos.a)
		direction = CW;
	else
		direction = CCW;
	while (direction == CW && 0 < pos.a--)
		rotate(light, TRUE);
	while (direction == CCW && pos.a++ < 0)
		r_rotate(light, TRUE);
	if (0 <= pos.b)
		direction = CW;
	else
		direction = CCW;
	while (direction == CW && 0 < pos.b--)
		rotate(dark, TRUE);
	while (direction == CCW && pos.b++ < 0)
		r_rotate(dark, TRUE);
	push(light, dark);
}

void	push_to_a(t_stack *light, t_stack *dark)
{
	int		group;

	group = set_next_node(dark, set_direction(dark))->group;
	// printf("group = %d\n", group);
	while (dark->prev->group == group)
	{
		__print_stack(dark);
		r_rotate(dark, TRUE);
	}
	while (dark->next->group == group)
		push(dark, light);
}

void	initialize_group(t_stack *light, int group, int direction)
{
	// int		direction;
	t_stack	*target;
	int		original;
	
	// direction = set_direction(light);
	// printf("direction = %d\n", direction);
	target = set_next_node(light, direction);
	// printf("target = %ld\n", target->data);
	original = target->group;
	while (target->group == original)
	{
		target->group = group + 1;
		target = set_next_node(target, direction);
		// printf("target->next = %ld\n", target->data);
	}
	// __print_stack(light);
}

void	insertion_sort(t_stack *light, t_stack *dark, int group)
{
	t_pos	pos;
	int		direction;

	if (light->group == B)
	{
		printf("Aしかできないよ!\n");
		return ;
	}
	direction = set_direction(light);
	// __print_stack(light);
	// __print_stack(dark);
	initialize_group(light, group, direction);
	if (direction == CCW)
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
		pos = calculate_best_node(light, dark, group + 1);
		push_best_node(light, dark, pos);
		// __print_stack(light);
		// __print_stack(dark);
	}
	push_to_a(light, dark);
	// __print_stack(light);
	// __print_stack(dark);
}