/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:31:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/02 15:46:10 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_next_node(t_stack *stack, int direction)
{	
	if (direction == CW)
		return (stack->next);
	else
		return (stack->prev);
}

int	set_direction(t_stack *light)
{
	if (light->next->group >= light->prev->group)
		return (CW);
	else
		return (CCW);
}

int	calculate_direction(t_stack *light, long reference)
{
	t_stack	*target;
	int		cnt;
	int		size;

	size = count_stack_size(light) / 2 + 1;
	target = light->next;
	cnt = 0;
	while (target->group != light->group)
	{
		cnt++;
		if (target->data == reference)
			break;
		target = target->next;
	}
	if (cnt < size)
		return (CW);
	else
		return (CCW);
}