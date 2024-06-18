/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:00:11 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/17 17:00:09 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_stack *a)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	if (count_stack_size(a) < 2)
		return ;
	first = a->next;
	second = first->next;
	third = second->next;
	a->next = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = a;
	third->prev = first;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*third;
	
	if (count_stack_size(b) < 2)
		return ;
	first = b->next;
	second = first->next;
	third = second->next;
	b->next = second;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = b;
	third->prev = first;
	ft_putstr_fd("sb\n", 1);
}



void	pa(t_stack *a, t_stack *b)
{
	t_stack	*target;
	
	if (count_stack_size(b) == 0)
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
	
	if (count_stack_size(a) == 0)
		return ;
	target = a->next;
	a->next = target->next;
	target->next->prev = a;
	target->next = b->next;
	target->prev = b;
	b->next = target;
	ft_putstr_fd("pb\n", 1);
}
