/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:45:28 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/21 18:12:55 by ttakino          ###   ########.fr       */
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

int	is_sorted(t_stack *a)
{
	t_stack *target;

	target = a->next;
	while (target->next != a)
	{
		if (target->data > target->next->data)
			return (FALSE);
		target = target->next;
	}
	return (TRUE);
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
		return (free(a), 1);
	initialize_stack(a, b);
	
	if (is_error(a, argc, argv) == TRUE)
	{
		ft_putstr_fd("Error\n", 2);
		clear_stack(a);
		clear_stack(b);
		return (0);
	}
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
	// __print_stack(a);
	// __print_stack(b);
	clear_stack(a);
	clear_stack(b);
	return (0);
}

//__attribute__((destructor))
//static void destructor() {
//   system("leaks -q push_swap");
//}
