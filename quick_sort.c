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

void	divide_group(t_stack *light, t_stack *dark, int group, int pos)
{
	t_stack	*target;
	int		direction;
	long	median;
	int		size;

	target = light->next;
	direction = 0;
	median = get_median(light, direction);
	// if (pos == B)
	// 	group = light->next->group;
	size = count_stack_size(light, GROUP);
	printf("{{median = %ld  group = %d  target = %ld}}\n", median, group, target->data);
	while (size-- > 0)
	{
		// target->group = group + 1;
		if (target->data < median && pos == A)
		{
			light->next->group = group + 1;
			push(light, dark);
		}
		else if (target->data > median && pos == B)
		{
			light->next->group = group + 1;
			push(light, dark);
		}
		else
		{
			rotate(light, TRUE);
		}
		if (direction == 0)
			target = light->next;
		// printf("direction = %d\n", direction);
		// if (target->group != group)
		// {
		// 	printf("\x1b[31mbreak\n\x1b[0m");
		// 	break ;
		// }
	}
}

void	quick_sort(t_stack *light, t_stack *dark, int group, int pos)
{
	int	size;
	int	flag;

	printf("\x1b[33mbefore____________________\n");
	__print_stack(light);
	__print_stack(dark);
		size = count_stack_size(light, GROUP);
	printf("\x1b[33msize = %d\n", size);
	printf("__________________________|\x1b[m\n");

	flag = FALSE;
	if (size == 2 & pos == B)
	{
		if (light->next->data < light->next->next->data)
			swap(light, TRUE);
		push(light, dark);
		push(light, dark);
	}
	else if (size == 2 && pos == A)
	{
		if (light->next->data > light->next->next->data)
			swap(light, TRUE);
	}
	else if (size == 1)
	{
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
	size = count_stack_size(light, GROUP);
	printf("\x1b[32msize = %d\n", size);
	printf("__________________________|\x1b[m\n");

	if (light->next == light || dark->next == dark)
		return ;

	//範囲を指定して再帰
	if (size > 2 && pos == A)
		quick_sort(light, dark, group + 1, pos);
	// if (size > 2 && pos == B)
	// 	quick_sort(light, dark, group, pos);
	else if (size == 2 && pos == A)
	{
		if (light->next->data > light->next->next->data)
			swap(light, TRUE);
		quick_sort(dark, light, group, B);
	}
	else if (pos == B)
	{
		if (flag == TRUE)
			quick_sort(dark, light, group, A);
		else
			quick_sort(light, dark, group, pos);
		// if (size == 2 && pos == B)
		// {
		// 	// if (light->next->data < light->next->next->data)
		// 	// 	swap(light, TRUE);
		// 	// push(light, dark);
		// 	// push(light, dark);
		// 	quick_sort(light, dark, group, pos);
		// }
		// else if (size == 1)
		// {
		// 	// push(light, dark);
		// 	quick_sort(light, dark, group, pos);
		// }
	}
}
