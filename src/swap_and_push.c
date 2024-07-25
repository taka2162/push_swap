/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:11 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:25:58 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h" 

void	swap(t_stack *stack, bool show_motion)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;

	if (count_stack_size(stack) < 2)
		return ;
	first = stack->next;
	second = first->next;
	third = second->next;
	stack->next = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = stack;
	third->prev = first;
	if (!show_motion)
		return ;
	if (stack->group == A)
		ft_putstr_fd("sa\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, false);
	swap(b, false);
	ft_putstr_fd("ss\n", 1);
}

void	push(t_stack *throw, t_stack *catch)
{
	t_stack	*target;
	t_stack	*second;
	t_stack	*c_next;

	if (count_stack_size(throw) == 0)
		return ;
	target = throw->next;
	second = target->next;
	c_next = catch->next;
	target->next = c_next;
	target->prev = catch;
	second->prev = throw;
	catch->next = target;
	throw->next = second;
	c_next->prev = target;
	if (throw->group == A)
		ft_putstr_fd("pb\n", 1);
	else if (throw->group == B)
		ft_putstr_fd("pa\n", 1);
}
