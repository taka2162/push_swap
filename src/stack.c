/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/22 16:12:58 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(t_stack **a, t_stack **b)
{
	(*a) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*a))
		exit(1);
	(*b) = (t_stack *)malloc(sizeof(t_stack));
	if (!(*b))
	{
		free((*a));
		exit(1);
	}
	(*a)->data = 0;
	(*b)->data = 0;
	(*a)->group = A;
	(*b)->group = B;
	(*a)->next = (*a);
	(*b)->next = (*b);
	(*a)->prev = (*a);
	(*b)->prev = (*b);
}

bool	add_node(t_stack *head, long data)
{
	t_stack	*new;
	t_stack	*first;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (false);
	new->data = data;
	new->group = 0;
	first = head->prev;
	new->next = head;
	new->prev = first;
	first->next = new;
	head->prev = new;
	return (true);
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

int	count_group_size(t_stack *light, int dir)
{
	int		count;
	t_stack	*target;
	int		group;

	count = 0;
	target = light->next;
	group = set_next_node(light, dir)->group;
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
