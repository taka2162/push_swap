/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_and_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:28:22 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:26:06 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

void	rotate(t_stack *stack, bool show_motion)
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
	if (!show_motion)
		return ;
	if (stack->group == A)
		ft_putstr_fd("ra\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, false);
	rotate(b, false);
	ft_putstr_fd("rr\n", 1);
}

void	r_rotate(t_stack *stack, bool show_motion)
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
	if (!show_motion)
		return ;
	if (stack->group == A)
		ft_putstr_fd("rra\n", 1);
	else if (stack->group == B)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *a, t_stack *b)
{
	r_rotate(a, false);
	r_rotate(b, false);
	ft_putstr_fd("rrr\n", 1);
}
