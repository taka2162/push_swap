/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:54:42 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/27 18:49:05 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	get_max(t_stack *light, int direction)
{
	long	max;
	t_stack	*target;
	int		group;

	max = LONG_MIN;
	target = set_next_node(light, direction);
	group = target->group;
	while (target->group == group)
	{
		if (max < target->data)
			max = target->data;
		target = set_next_node(target, direction);
	}
	// printf("max = %ld\n", max);
	return (max);
}

int	calculate_push_cost(t_stack *light, long max, int direction)
{
	int		group;
	int		cnt;
	t_stack	*target;

	group = set_next_node(light, direction);
	cnt = 0;
	target = light->next;
	while (target->group == group)
	{
		if (target->data == max)
			break;
		cnt++;
		target = target->next;
	}
	target = light->prev;
	while (target->group == group)
	{
		if (target->data == max)
			break;
		cnt--;
		target = target->prev;
	}
	if (cnt <= 0)
		return (CW);
	else
		return (CCW);
}

void	insertion_sort(t_stack *light, t_stack *dark, int direction)
{
	int		size;
	long	max;
	// t_stack	*target;

	if (light->group != B)
	{
		printf("Bしかできないよ!\n");
		return ;
	}

	size = count_stack_size(light, GROUP, direction);
	// max = set_next_node(light, direction)->data;
	max = get_max(light, direction);
	// printf("max = %ld\n", max);
	// target = set_next_node(light, direction);
	while (0 < size--)
	{
		if (direction == CCW)
			r_rotate(light, TRUE);
		if (light->next->data == max)
			push(light, dark);
		else if (direction == CW)
			rotate(light, TRUE);
	}
	if (dark->next->group != set_next_node(light, direction)->group)
		return ;
	else
		insertion_sort(light, dark, direction * -1);
}
