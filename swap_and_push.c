/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:11 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/23 17:11:39 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h" 

void	swap(t_stack *stack, int show_motion)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	if (count_stack_size(stack, STACK) < 2)
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
	if (show_motion == FALSE)
		return ;
	if (stack->group == A)
		ft_putstr_fd("sa\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, FALSE);
	swap(b, FALSE);
	ft_putstr_fd("ss\n", 1);
}

void	push(t_stack *throw, t_stack *catch)
{
	t_stack	*target;
	t_stack	*second;
	t_stack	*c_next;
	
	if (count_stack_size(throw, STACK) == 0)
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
	if (throw->group == -1)
		ft_putstr_fd("pb\n", 1);
	else if (throw->group == -2)
		ft_putstr_fd("pa\n", 1);
}
