/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/05 18:07:56 by ttakino          ###   ########.fr       */
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
	t_stack	*next;
	int		size;

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
	// printf("value = %ld  direction = %d  num = %d\n",value, direction, num);
	// printf("b->group = %d  dark->next->group = %d\n", target->group, dark->next->group);
	while (target->group == dark->next->group)
	{
		next = set_next_node(target, direction);
		// printf("+++%d * (%ld - %ld) = %ld+++\n",
		// 	num, target->data, next->data,
		// 		num * (target->data - next->data));
		// printf("---%d * (%ld - %ld) = %ld---\n", 
		// 	num, value, target->data,
		// 		 num * (value - target->data));
		if (0 < num * (value - target->data))
			{
				break ;
			}
		pos++;
		if (num * (target->data - next->data) < 0)
			break ;
		target = next;
		//printf("target = %ld\n", target->data);
	}
	// printf("pos = %d\n", pos);
	pos *= (direction / 3);
	size = count_stack_size(dark);
	// printf("pos = %d  size = %d\n", pos, size);
	if (size / 2 < abs(pos))
		pos = (size - abs(pos)) * (direction * -1 / 3);
	// printf("value = %ld  pos = %d\n",value, pos);
	// printf("\x1b[0m");
	return (pos);
}

t_pos	calculate_best_node(t_stack *light, t_stack *dark, t_pos pos, int direction)
{
	// int		min;
	int		size;
	int		pos_a_b[2];
	t_stack	*target;

	// min = INT_MAX;
	size = count_stack_size(light);
	pos_a_b[0] = 0;
	target = set_next_node(light, direction);
	while (target->group == dark->next->group)
	{
		pos_a_b[1] = calculate_best_position(dark, target->data);
		if (abs(pos_a_b[0]) + abs(pos_a_b[1]) < abs(pos.a) + abs(pos.b))
		{
			if (abs(pos_a_b[0]) > size / 2)
				pos_a_b[0] = (size - abs(pos_a_b[0])) * -1;
			// min = abs(pos_a_b[0]) + abs(pos_a_b[1]);
			pos.a = pos_a_b[0] * (direction / 3);
			pos.b = pos_a_b[1];
		}
		pos_a_b[0]++;
		target = set_next_node(target, direction);
	}
	if (direction == CW)
		calculate_best_node(light, dark, pos, direction * -1);
	
	return (pos);
}

// t_pos	cal_from_back(t_stack *light, t_stack *dark, int size, int group)
// {
// 	// int		min;
// 	int		pos_a_b[2];
// 	t_pos	pos;
// 	t_stack	*target;

// 	// min = INT_MAX;
// 	pos_a_b[0] = 0;
// 	target = light->prev;
// 	while (target->group == group)
// 	{
// 		pos_a_b[1] = calculate_best_position(dark, target->data);
// 		if (abs(pos_a_b[0]) + abs(pos_a_b[1]) < abs(pos.a) + abs(pos.b))
// 		{
// 			if (abs(pos_a_b[0]) > size / 2)
// 				pos_a_b[0] = (size - abs(pos_a_b[0])) * -1;
// 			// min = abs(pos_a_b[0]) + abs(pos_a_b[1]);
// 			pos.a = pos_a_b[0] * -1;
// 			pos.b = pos_a_b[1];
// 		}
// 		pos_a_b[0]++;
// 		target = target->prev;
// 	}
// 	return (pos);
// }	

// t_pos	calculate_best_node(t_stack *light, t_stack *dark, int group)
// {
// 	int		size;
// 	t_pos	front;
// 	t_pos	back;

// 	size = (count_stack_size(light));
// 	front = cal_from_front(light, dark, size, group);
// 	back = cal_from_back(light, dark, size, group);
// 	if (front.a + front.b < back.a + back.b)
// 	{
// 		printf("pos.a = %d  pos.b = %d  front\n", front.a, front.b);
// 		return (front);
// 	}
// 	else
// 	{
// 		printf("pos.a = %d  pos.b = %d  back\n", back.a, back.b);
// 		return (back);
// 	}
// 	// i = 1;
// 	// target = light->prev;
// 	// while (target->group == group)
// 	// {
// 	// 	pos_b = calculate_best_position(dark, target->data);
// 	// 	if (abs(pos_b) + i < min)
// 	// 	{
// 	// 		min = abs(pos_b) + i;
// 	// 		pos.a = i * -1;
// 	// 		pos.b = pos_b;
// 	// 	}
// 	// 	i++;
// 	// 	target = target->prev;
// 	// }
// 	// if (pos.a < 0)
// 		// printf("\x1b[32mrra!!!\n\x1b[0m");
// }

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
	int		count;
	long	max;
	t_stack	*target;

	group = set_next_node(dark, set_direction(dark))->group;
	// printf("group = %d\n", group);
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
	__print_stack(light);
	__print_stack(dark);
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
		__print_stack(light);
		__print_stack(dark);
		pos = calculate_best_node(light, dark, pos, CW);
		push_best_node(light, dark, pos);
		// __print_stack(light);
		// __print_stack(dark);s
	}
	push_to_a(light, dark);
	// __print_stack(light);
	// __print_stack(dark);
}