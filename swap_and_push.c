/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_and_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:11 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 16:28:12 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h" 

void	swap(t_stack *stack, int stack_type, int show_motion)
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
	if (stack_type == A)
		ft_putstr_fd("sa\n", 1);
	else if (stack_type == B)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a, t_stack *b)
{
	swap(a, A, FALSE);
	swap(b, B, FALSE);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *a, t_stack *b)
{
	t_stack	*target;
	
	if (count_stack_size(b, STACK) == 0)
		return ;
	target = b->next;
	b->next = target->next;
	target->next->prev = b;
	target->next = a->next;
	target->prev = a;
	a->next = target;
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a, t_stack *b)
{
	t_stack	*target;
	
	if (count_stack_size(a, STACK) == 0)
		return ;
	target = a->next;
	a->next = target->next;
	target->next->prev = a;
	target->next = b->next;
	target->prev = b;
	b->next = target;
	ft_putstr_fd("pb\n", 1);
}
