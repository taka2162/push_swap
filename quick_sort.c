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

void	push_to_dark(t_stack **light, t_stack *dark, int group, int direction)
{
	set_next_node(*light, direction)->group = group + 1;
	if (direction == CCW)
		r_rotate(*light, TRUE);
	push(*light, dark);
}

void	divide_group(t_stack *light, t_stack *dark, int group, int direction)
{
	t_stack	*target;
	long	median;
	int		size;

	// printf("\x1b[32mdivide_group\x1b[0m\n");
	target = set_next_node(light, direction);
	median = get_median(light, direction);
	// printf("expect -> %ld median = %ld\n", get_median_expect(light, direction), median);
	size = count_group_size(light, direction);
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
		else if (target->data >= median && light->group == B)
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
}

void	sort_one_or_two(t_stack *light, t_stack *dark, int size, int direction)
{
	// printf("\x1b[34msort_one_or_two\x1b[0m\n");
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
}

// void	sort_three(t_stack *light, t_stack *dark, int direction)
// {
// 	int	size;
// 	int	count;
// 	int	max;

// 	if (light->group == A && count_stack_size(light) == 3)
// 	{
// 		sort_three_nodes(light);
// 		return ;
// 	}
// 	size = count_group_size(light, direction);
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
	// printf("\x1b[33mbefore____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// printf("direction = %d\n", direction);
	// printf("\x1b[33msize = %d\n", size);
	// printf("__________________________|\x1b[m\n");

	flag = FALSE;
	if (size <= 2)
		sort_one_or_two(light, dark, size, direction);
	else if (size <= 9)
		flag = extreme_sort(light, dark, group, direction);
	else if (size <= 365 && light->group == A)
	{
		// printf("zzzinsertion_sortzzz\n");
		insertion_sort(light, dark, group);
		group++;
	}
	else
	{
		divide_group(light, dark, group, direction);
		flag = TRUE;
	}

	size = count_group_size(light, direction);
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
