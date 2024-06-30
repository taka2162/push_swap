/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:42 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/30 17:26:03 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_max(t_stack *light, int direction)
{
	long	max;
	t_stack	*target;
	int		group;

	max = LONG_MIN;
	target = light->next;
	group = set_next_node(light, direction)->group;
	while (target->group == group)
	{
		if (max < target->data)
			max = target->data;
		target = target->next;
	}
	target = light->prev;
	while (target->group == group)
	{
		if (max < target->data)
			max = target->data;
		target = target->prev;
	}
	// printf("max = %ld\n", max);
	return (max);
}

int	set_next_direction(t_stack *light, int direction)
{
	if (light->next->group > light->prev->group)
		return (CW);
	else if (light->next->group == light->prev->group)
		return (direction);
	else
		return (CCW);
}

int	calculate_push_cost(t_stack *light, long max, int direction)
{
	t_stack	*target;
	int		cnt;
	int		size;


	max = get_max(light, direction);
	// target = set_next_node(light, direction);
	size = count_stack_size(light, STACK, direction) / 2 + 1;
	// printf("sise = %d\n", size);	
	target = light->next;
	cnt = 0;
	while (target->group != light->group)
	{
		cnt++;
		if (target->data == max)
			break;
		target = target->next;
	}
	// printf("cnt = %d\n", cnt);
	if (cnt < size)
		return (CW);
	else
		return (CCW);
}

void	insertion_sort(t_stack *light, t_stack *dark, int direction)
{
	int		size;
	long	max;
	int		cost;

	if (light->group != B)
	{
		printf("Bしかできないよ!\n");
		return ;
	}

	// printf("direction = %d\n", direction);
	size = count_stack_size(light, GROUP, direction);
	max = get_max(light, direction);
	// printf("max = %ld\n", max);
	cost = calculate_push_cost(light, max, direction);
	// __print_stack(light);
	// printf("cost = %d\n", cost);
	while (0 < size--)
	{
		if (cost == CCW)
			r_rotate(light, TRUE);
		if (light->next->data == max)
		{
			push(light, dark);
			break ;
		}
		else if (cost == CW)
			rotate(light, TRUE);
	}
	if (dark->next->group != light->next->group
		&& dark->next->group != light->prev->group)
	{
		// printf("\x1b[34mreturn\n\x1b[0m");
		return ;
	}
	else
		insertion_sort(light, dark, set_next_direction(light, direction));
}
