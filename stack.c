/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/30 17:18:36 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

int	count_stack_size(t_stack *stack, int sign, int direction)
{
	int		size;
	t_stack	*head;
	int		group;

	size = 0;
	head = stack;
	stack = set_next_node(stack, direction);
	group = stack->group;
	while (stack != head)
	{
		if (stack->group != group && sign == GROUP)
			break ;
		size++;
		stack = set_next_node(stack, direction);
	}
	return (size);
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
		if (head->group == A)
			printf("\x1b[35m");
		else
			printf("\x1b[36m");
		printf("%ld\x1b[m-%d ", stack->data, stack->group);
		stack = stack->next;
	}
	printf("\x1b[m");
	printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;


	if (argc < 2)
		return (0);
	a = (t_stack *)malloc(sizeof(t_stack));
	if (a == NULL)
		return (1);
	b = (t_stack *)malloc(sizeof(t_stack));
	if (b == NULL)
		return (1);
	initialize_stack(a, b);
	input_argvs(a, argc, argv);
	// __print_stack(a);
	// __print_stack(b);
	// push(a, b);
	// push(a, b);
	// push(a, b);
	// push(a, b);
	// push(b, a);
	// push(b, a);
	// __print_stack(a);
	// __print_stack(b);
	// push(b, a);
	// push(b, a);
	// push(b, a);
	// swap(a, TRUE);
	// swap(b, TRUE);
	// ss(a, b);
	// rotate(a, TRUE);
	// rotate(b, TRUE);
	// r_rotate(a, TRUE);
	// r_rotate(b, TRUE);
	// rrr(a, b);
	// printf("pivot = %ld\n", get_median(a, 0));
	// printf("--------------------------------------------------------|\n");
	quick_sort(a, b, 0);
	// printf("--------------------------------------------------------|\n");
	// __print_stack(a);
	// __print_stack(b);
	// printf("a_size = %d b_size = %d\n", count_stack_size(a, STACK, 0), count_stack_size(b, STACK, 0));
	clear_stack(a);
	clear_stack(b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
   system("leaks -q push_swap");
}