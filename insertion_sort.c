/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:59:51 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/02 16:44:08 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_best_position(t_stack *dark, long value, int group)
{
	int		pos;
	int		direction;
	int		num;
	t_stack	*target;

	pos = 0;
	if (value < dark->next->data)
	{
		direction = CW;
		num = 1;
	}
	else
	{
		direction = CCW;
		num = -1;
	}
	while (target->group == dark->next->group)
	{
		pos++;
		if (0 < num * target->data - set_next_node(dark, direction)->data)
			break ;
		target = set_next_node(dark, direction);
	}
}

int	calculate_best_node(t_stack *light, t_stack *dark, int group)
{
	int		answer;
	int		pos;
	t_stack	*target;

	pos = INT_MAX;
	target = light->next;
	while (target->group == group)
	{
		answer = calculate_best_position(dark, target->data, group);
		if (answer < pos)
			answer = pos;
		target = target->next;
	}
}

void	insertion_sort(t_stack *light, t_stack *dark, int group)
{
	if (light->group == B)
	{
		printf("Aしかできないよ!\n");
		return ;
	}

	light->next->group = group + 1;
	push(light, dark);
	light->next->group = group + 1;
	push(light, dark);
	if (dark->next->data < dark->next->next->data)
		swap(dark, TRUE);
}