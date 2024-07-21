/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:45:28 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/21 19:29:47 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

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

void	error_exit(t_stack *a, t_stack *b)
{
	clear_stack(a);
	clear_stack(b);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

int	is_sorted(t_stack *a)
{
	t_stack	*target;

	target = a->next;
	while (target->next != a)
	{
		if (target->data > target->next->data)
			return (FALSE);
		target = target->next;
	}
	return (TRUE);
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

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	initialize_stack(&a, &b);
	if (is_error(a, argc, argv) == TRUE)
		error_exit(a, b);
	if (is_sorted(a) == TRUE)
		return (clear_stack(a), clear_stack(b), 0);
	else if (count_stack_size(a) <= 2)
		sort_one_or_two(a, b, count_stack_size(a), CW);
	else if (count_stack_size(a) == 3)
		sort_three_nodes(a);
	else if (count_stack_size(a) <= 365)
		insertion_sort(a, b, 0, TRUE);
	else
		quick_sort(a, b, 0);
	clear_stack(a);
	clear_stack(b);
	return (0);
}

//__attribute__((destructor))
//static void destructor() {
//   system("leaks -q push_swap");
//}
