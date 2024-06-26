/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:28:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/26 16:00:00 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	rotate(t_stack *stack, int show_motion)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*second;

	if (stack->next->next == stack)
		return ;
	first = stack->next;
	last = stack->prev;
	second = first->next;
	stack->next = second;
	stack->prev = first;
	first->next = stack;
	first->prev = last;
	last->next = first;
	second->prev = stack;
	if (show_motion == FALSE)
		return ;
	if (stack->group == A)
		ft_putstr_fd("ra\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, FALSE);
	rotate(b, FALSE);
	ft_putstr_fd("rr\n", 1);
}

void	r_rotate(t_stack *stack, int show_motion)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*l_second;

	if (stack->next->next == stack)
		return ;
	first = stack->next;
	last = stack->prev;
	l_second = last->prev;
	stack->next = last;
	stack->prev = l_second;
	first->prev = last;
	last->next = first;
	last->prev = stack;
	l_second->next = stack;
	if (show_motion == FALSE)
		return ;
	if (stack->group == A)	
		ft_putstr_fd("rra\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a, FALSE);
	r_rotate(b, FALSE);
	ft_putstr_fd("rrr\n", 1);
}