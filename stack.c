/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/17 16:58:21 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

void	initialize_stack(t_stack *a, t_stack *b)
{
	a->next = a;
	b->next = b;
	a->prev = a;
	b->prev = b;
}

int	count_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*head;

	size = 0;
	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

void	add_node(t_stack *head, long data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	new->data = data;
	new->next = head->next;
	new->prev = head->prev;
	head->next = new;
	head->prev = new;
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

void	__print_stack(t_stack *stack)
{
	t_stack	*head;

	head = stack;
	stack = stack->next;
	while (stack != head)
	{
		printf("%ld ", stack->data);
		stack = stack->next;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL)
		return (1);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (b == NULL)
		return (1);
	initialize_stack(a, b);
	add_node(a, 7);
	add_node(b, 8);
	add_node(a, 90);
	add_node(b, 28);
	add_node(a, 12);
	__print_stack(a);
	__print_stack(b);
	// pa(a, b);
	sb(b);
	__print_stack(a);
	__print_stack(b);
	printf("a_size = %d b_size = %d\n", count_stack_size(a), count_stack_size(b));
	clear_stack(a);
	clear_stack(b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
   system("leaks -q push_swap");
}