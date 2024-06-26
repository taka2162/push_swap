/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:55:20 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_direction(t_stack *light)
{
	if (light->next->group >= light->prev->group)
		return (CW);
	else
		return (CCW);
}

void	push_to_dark(t_stack **light, t_stack *dark, int group, int direction)
{
	set_next_node(*light, direction)->group = group + 1;
	if (direction == CCW)
		r_rotate(*light, TRUE);
	push(*light, dark);
}

int	divide_group(t_stack *light, t_stack *dark, int group, int direction)
{
	t_stack	*target;
	long	median;
	int		size;

	target = set_next_node(light, direction);
	median = get_median(light, direction);
	// printf("expect -> %ld median = %ld\n", get_median_expect(light, direction), median);
	size = count_group_size(light, direction);
	// size = count_stack_size(light, GROUP, direction);
	// printf("{{direction = %d  median = %ld  group = %d  target = %ld}}\n", direction, median, group, target->data);
	while (size-- > 0)
	{
		if (target->data < median && light->group == A)
		{
			push_to_dark(&light, dark, group, direction);
			// if (direction == 0)
			// 	light->next->group = group + 1;
			// else
			// {
			// 	light->prev->group = group + 1;
			// 	r_rotate(light, TRUE);
			// }
			// push(light, dark);
		}
		else if (target->data > median && light->group == B)
		{
			push_to_dark(&light, dark, group, direction);
			// if (direction == 0)
			// 	light->next->group = group + 1;
			// else
			// {
			// 	light->prev->group = group + 1;
			// 	r_rotate(light, TRUE);
			// }
			// push(light, dark);
		}
		else
		{
			if (direction == CW)
				rotate(light, TRUE);
			else
				r_rotate(light, TRUE);
		}
		target = set_next_node(light, direction);
	}
	return (TRUE);
}

int	sort_one_or_two(t_stack *light, t_stack *dark, int size, int direction)
{
	// printf("sort_one_or_two\n");
	if (direction == CCW)
	{
		r_rotate(light, TRUE);
		if (size >= 2)
			r_rotate(light, TRUE);
	}
	if (light->group == A && size == 2
		&& light->next->data > light->next->next->data)
		swap(light, TRUE);
	else if (light->group == B)
	{
		if (light->next->data < light->next->next->data && size == 2)
			swap(light, TRUE);
		push(light, dark);
		if (2 <= size)
			push(light, dark);
	}
	return (FALSE);
}

// void	sort_three(t_stack *light, t_stack *dark, int direction)
// {
// 	int	size;
// 	int	count;
// 	int	max;

// 	if (light->group == A && count_stack_size(light, STACK, direction) == 3)
// 	{
// 		sort_three_nodes(light);
// 		return ;
// 	}
// 	size = count_stack_size(light, GROUP, direction);
// 	count = 0;
// 	while (0 < size--)
// 	{
// 		max = get_max(light, direction);
// 		if (direction == CCW)
// 			r_rotate(light, TRUE);
// 		if (light->next->data == max)
// 		{
// 			push(light, dark);
// 			count++;
// 		}
// 		else if (direction == CW)
// 			rotate(light, TRUE);
// 	}
// 	if (count <= 2)
// 	{
// 		// printf("direction == %d  %d\n", direction, direction * -1);
// 		sort_one_or_two(light, dark, 3 - count, direction * -1);
// 	}
// 	// __print_stack(light);
// 	return ;
// }

void	quick_sort(t_stack *light, t_stack *dark, int group)
{
	int	direction;
	int	size;
	int	flag;

	direction = set_direction(light);
	// printf("direction = %d\n", direction);

	// if (group > 8)
	// 	return ;

	size = count_group_size(light, direction);
	// // size = count_stack_size(light, GROUP, direction);
	// printf("\x1b[33mbefore____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// printf("\x1b[33msize = %d\n", size);
	// printf("__________________________|\x1b[m\n");

	if (size <= 2)
	{
		flag = sort_one_or_two(light, dark, size, direction);
	}
	else if (size <= 9)
		flag = insertion_sort(light, dark, group, direction);
	else
		flag = divide_group(light, dark, group, direction);

	size = count_group_size(light, direction);
	// // size = count_stack_size(light, GROUP, direction);
	// printf("\x1b[32mafter____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// printf("flag = %d\n", flag);
	// printf("\x1b[32msize = %d\n", size);
	// printf("__________________________|\x1b[m\n");

	if (light->next == light || dark->next == dark)
		return ;

	//範囲を指定して再帰
	if (light->group == A)
	{
		if (flag == TRUE)
			quick_sort(light, dark, group + 1);
		else
			quick_sort(dark, light, group);
	}
	else if (light->group == B)
	{
		if (flag == TRUE)
			quick_sort(dark, light, group + 1);
		else
			quick_sort(light, dark, group);
	}
}
