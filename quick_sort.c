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

void	quick_sort(t_stack *light, t_stack *dark)
{
	t_stack	*target;
	int		size;
	int		direction;
	long	median;
	int		group;


	// printf("group size = %d\n", count_stack_size(light, GROUP));
	// printf("group = %d\n", light->next->group);
	__print_stack(light);
	__print_stack(dark);
	// if (count_stack_size(light, STACK) < 3)
	// {
	// 	if (count_stack_size(light, STACK) == 2)
	// 	{
	// 		if (light->next->data < light->next->next->data)
	// 			swap(light, TRUE);
	// 		push(light, dark);
	// 		push(light, dark);
	// 	}
	// 	else
	// 		push(light, dark);
	// 	return ;
	// }
	if (count_stack_size(light, GROUP) == 0)
	{
		return ;
	}
	else if (count_stack_size(light, GROUP) == 1)
	{
		push(light, dark);
		quick_sort(light, dark);
		return ;
	}
	else if (count_stack_size(light , GROUP) == 2)
	{
		if (light->next->data < light->next->next->data)
			swap(light, TRUE);
		push(light, dark);
		push(light, dark);
		quick_sort(light, dark);
		return ;
	}
	
	if (dark->next->group - 1 == light->next->group)
	{
		target = light->next;
		direction = 0;
	}
	else
	{
		target = light->prev;
		direction = 1;
	}
	size = 0;
	median = get_median(target, direction);
	group = target->group;
	printf("median = %ld\n", median);
	size = count_stack_size(light, GROUP);
	while (0 < size && target->group == group)
	{
		if (direction == 1)
			r_rotate(light, TRUE);
		printf("target = %ld\n",  target->data);
		if (target->data < median && light->group == A)
			push(light, dark);
		else if (target->data > median && light->group == B)
			push(light, dark);
		else
		{
			target->group = group + 1;
			if (direction == 0)
				rotate(light, TRUE);
		}
		size--;
		if (direction == 0)
			target = light->next;
		else
			target = light->prev;
		// printf("light = %d   ", light->group);
		// printf("size = %d target = %ld group = %d\n", size, target->data, target->group);
	}

	if (light->group == A)
	{
		if (count_stack_size(light, GROUP) > 2)
		{
			// __print_stack(light);
			// __print_stack(dark);
			quick_sort(light, dark);
		}
		else
		{
			if (light->next->data > light->next->next->data)
				swap(light, TRUE);
			// __print_stack(light);
			// __print_stack(dark);
			quick_sort(dark, light);
		}
	}
	else if (light->group == B)
	{
		if (count_stack_size(dark, GROUP) > 2)
		{
			quick_sort(dark, light);
		}
		else if (count_stack_size(dark, GROUP) == 2)
		{
			if (dark->next->data > dark->next->next->data)
				swap(dark, TRUE);
			quick_sort(light, dark);
		}
	}

	return ;


	// if (light->group == A)
	// {
	// 	printf("A, ");
	// 	if (count_stack_size(light, GROUP) > 3)
	// 	{
	// 		printf(">3\n");
	// 		quick_sort(light, dark);
	// 	}
	// 	else if (count_stack_size(light, GROUP) == 3)
	// 	{
	// 		sort_three_nodes(light);
	// 		push(dark, light);
	// 		push(dark, light);
	// 		if (light->next->data > light->next->next->data)
	// 			swap(light, TRUE);
	// 		printf("3\n");
	// 		quick_sort(dark, light);
	// 	}
	// 	else if (count_stack_size(light, GROUP) == 2)
	// 	{
	// 		if (light->next->data > light->next->next->data)
	// 		{
	// 			swap(light, TRUE);
	// 		}
	// 		printf("2, \n");
	// 		quick_sort(dark, light);
	// 	}
	// 	else
	// 	{
	// 		printf("Error---A\n");
	// 		return ;
	// 	}
	// }
	// else
	// {
	// 	printf("B, ");
	// 	if (count_stack_size(dark, GROUP) >= 3)
	// 	{
	// 		quick_sort(dark, light);
	// 	}
	// 	else if (count_stack_size(dark, GROUP) == 2)
	// 	{
	// 		if (dark->next->data > light->next->next->data)
	// 		{
	// 			swap(light, TRUE);
	// 		}
	// 		push(light, dark);
	// 		push(light, dark);
	// 		printf("2\n");
	// 		quick_sort(dark, light);
	// 	}
	// 	else
	// 	{
	// 		printf("Error---B\n");
	// 		return ;
	// 	}
	// }
}
