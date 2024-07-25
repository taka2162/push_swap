/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:31:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:24:00 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*set_next_node(t_stack *stack, int dir)
{	
	if (dir == CW)
		return (stack->next);
	else
		return (stack->prev);
}

int	set_dir(t_stack *light)
{
	if (light->next->group >= light->prev->group)
		return (CW);
	else
		return (CCW);
}
