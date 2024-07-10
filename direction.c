/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 15:31:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/10 16:36:48 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
