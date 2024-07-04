/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:45 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/04 18:09:32 by ttakino          ###   ########.fr       */
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

// int	count_stack_size(t_stack *stack, int sign, int direction)
// {
// 	int		size;
// 	t_stack	*head;
// 	int		group;

// 	size = 0;
// 	head = stack;
// 	stack = set_next_node(stack, direction);
// 	group = stack->group;
// 	while (stack != head)
// 	{
// 		if (stack->group != group && sign == GROUP)
// 			break ;
// 		size++;
// 		stack = set_next_node(stack, direction);
// 	}
// 	return (size);
// }

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
	// printf("a_size = %d b_size = %d\n", count_stack_size(a), count_stack_size(b));
	clear_stack(a);
	clear_stack(b);
	return (0);
}

// __attribute__((destructor))
// static void destructor() {
//    system("leaks -q push_swap");
// }