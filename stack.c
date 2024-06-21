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
	a->group = -1;
	b->group = -2;
	a->next = a;
	b->next = b;
	a->prev = a;
	b->prev = b;
}

int	count_stack_size(t_stack *stack, int sign)
{
	int		size;
	t_stack	*head;
	int		group;

	size = 0;
	head = stack;
	stack = stack->next;
	group = stack->group;
	while (stack != head)
	{
		size++;
		if (stack->group != group && sign == GROUP)
			break ;
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
	while (stack != head)
	{
		if (color == A)
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
	__print_stack(a, A);
	__print_stack(b, B);
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
	printf("median = %ld\n", get_median(a));
	printf("--------------------------------------------------------|\n");
	quick_sort(a, b);
	printf("--------------------------------------------------------|\n");
	__print_stack(a, A);
	__print_stack(b, B);
	printf("a_size = %d b_size = %d\n", count_stack_size(a, STACK), count_stack_size(b, STACK));
	clear_stack(a);
	clear_stack(b);
	return (0);
}

__attribute__((destructor))
static void destructor() {
   system("leaks -q push_swap");
}