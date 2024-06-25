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
	if (light->next->data >= light->prev->data)
		return (0);
	else
		return (1);
}

void	divide_group(t_stack *light, t_stack *dark, int group, int direction)
{
	t_stack	*target;
	long	median;
	int		size;

	if (direction == 0)
		target = light->next;
	else
		target = light->prev;
	median = get_median(light, direction);
	size = count_stack_size(light, GROUP, direction);
	printf("{{direction = %d  median = %ld  group = %d  target = %ld}}\n", direction, median, group, target->data);
	while (size-- > 0)
	{
		if (target->data < median && light->group == A)
		{
			if (direction == 0)
				light->next->group = group + 1;
			else
			{
				light->prev->group = group + 1;
				r_rotate(light, TRUE);
			}
			push(light, dark);
		}
		else if (target->data > median && light->group == B)
		{
			if (direction == 0)
				light->next->group = group + 1;
			else
			{
				light->prev->group = group + 1;
				r_rotate(light, TRUE);
			}
			push(light, dark);
		}
		else
		{
			if (direction == 0)
				rotate(light, TRUE);
			else
				r_rotate(light, TRUE);
		}
		if (direction == 0)
			target = light->next;
		else
			target = light->prev;
	}
}

void	quick_sort(t_stack *light, t_stack *dark, int group, int pos)
{
	int	direction;
	int	size;
	int	flag;

	direction = set_direction(light);

	printf("\x1b[33mbefore____________________\n");
	__print_stack(light);
	__print_stack(dark);
		size = count_stack_size(light, GROUP, 0);
	printf("\x1b[33msize = %d\n", size);
	printf("__________________________|\x1b[m\n");

	flag = FALSE;
	if (direction == 1 && size == 2)
	{
		r_rotate(light, TRUE);
		r_rotate(light, TRUE);
	}
	if (direction == 1 && size == 1)
		r_rotate(light, TRUE);
	if (pos == A && size < 3)
	{
		if (size == 2 && light->next->data > light->next->next->data)
			swap(light, TRUE);
	}
	else if (pos == B && size < 3)
	{
		if (size == 2)
		{
			if (light->next->data < light->next->next->data)
				swap(light, TRUE);
			push(light, dark);
			push(light, dark);
		}
		else if (size == 1)
			push(light, dark);
	}
	else
	{
		divide_group(light, dark, group, pos);
		flag = TRUE;
	}

	printf("\x1b[32mafter____________________\n");
	__print_stack(light);
	__print_stack(dark);
	size = count_stack_size(light, GROUP, 0);
	printf("\x1b[32msize = %d\n", size);
	printf("__________________________|\x1b[m\n");

	if (light->next == light || dark->next == dark)
		return ;

	//範囲を指定して再帰
	if (pos == A)
	{
		if (flag == TRUE)
			quick_sort(light, dark, group + 1, direction);
		else
			quick_sort(dark, light, group, direction);
	}
	else if (pos == B)
	{
		if (flag == TRUE)
			quick_sort(dark, light, group + 1, direction);
		else
			quick_sort(light, dark, group, direction);
	}
}
