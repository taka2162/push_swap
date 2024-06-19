/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:33:56 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	initialize_stack(t_stack *a, t_stack *b)
{
	a->data = 0;
	b->data = 0;
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

void	__print_stack(t_stack *stack, int color)
{
	t_stack	*head;

	head = stack;
	stack = stack->next;
	if (color == 0)
		printf("\x1b[35m");
	else
		printf("\x1b[36m");
	while (stack != head)
	{
		printf("%ld ", stack->data);
		stack = stack->next;
	}
	printf("\x1b[m");
	printf("\n");
}

int	main(int argc, char **argv)
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
	input_argvs(a, argc, argv);
	__print_stack(a, 0);
	__print_stack(b, 1);
	//pa(a, b);
	//pb(a, b);
	// swap(a, A, TRUE);
	// swap(b, B, TRUE);
	// ss(a, b);
	// rotate(a, A, TRUE);
	// rotate(b, B, TRUE);
	// r_rotate(a, A, TRUE);
	// r_rotate(b, B, TRUE);
	// rrr(a, b);
	printf("--------------------------------------------------------|\n");
	sort_three_nodes(a);
	printf("--------------------------------------------------------|\n");
	__print_stack(a, 0);
	__print_stack(b, 1);
	printf("a_size = %d b_size = %d\n", count_stack_size(a), count_stack_size(b));
	clear_stack(a);
	clear_stack(b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
   system("leaks -q push_swap");
}