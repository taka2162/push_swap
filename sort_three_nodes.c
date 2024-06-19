/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nodes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:33:35 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:13:39 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_nodes(t_stack *stack)
{
	long	first;
	long	second;
	long	third;

	first = stack->next->data;
	second = stack->next->next->data;
	third = stack->next->next->next->data;
	if (first > second && second > third)
	{
		swap(stack, A, TRUE);
		r_rotate(stack, A, TRUE);
	}
	else if (first > second && third > second && first > third)
		rotate(stack, A, TRUE);
	else if (first > second && third > second && third > first)
		swap(stack, A, TRUE);
	else if (second > first && second > third && first > third)
		r_rotate(stack, A, TRUE);
	else if (second > first && second > third &&third > first)
	{
			r_rotate(stack, A, TRUE);
			swap(stack, A, TRUE);
	}
}