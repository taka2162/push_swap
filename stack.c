/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/21 17:45:04 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_stack *a, t_stack *b)
{
	a->data = 0;
	b->data = 0;
	a->group = -1;
	b->group = -2;
	a->next = a;
	b->next = b;
	a->prev = a;
	b->prev = b;
}

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
		swap(stack, TRUE);
		r_rotate(stack, TRUE);
	}
	else if (first > second && third > second && first > third)
		rotate(stack, TRUE);
	else if (first > second && third > second && third > first)
		swap(stack, TRUE);
	else if (second > first && second > third && first > third)
		r_rotate(stack, TRUE);
	else if (second > first && second > third && third > first)
	{
		r_rotate(stack, TRUE);
		swap(stack, TRUE);
	}
}

int	count_stack_size(t_stack *stack)
{
	t_stack	*target;
	int		size;

	size = 0;
	target = stack->next;
	while (target != stack)
	{
		size++;
		target = target->next;
	}
	return (size);
}

int	count_group_size(t_stack *light, int direction)
{
	int		count;
	t_stack	*target;
	int		group;

	count = 0;
	target = light->next;
	group = set_next_node(light, direction)->group;
	while (target->group == group)
	{
		count++;
		target = target->next;
		if (target->group == light->group)
			return (count);
	}
	target = light->prev;
	while (target->group == group)
	{
		count++;
		target = target->prev;
	}
	return (count);
}

void	clear_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*next;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		next = stack->next;
		free(stack);
		stack = NULL;
		stack = next;
	}
	free(head);
	head = NULL;
}
