/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:55:15 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:55:20 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*head;
	int		size;
	long	median;
	int		group;

	target = a->next;
	head = target->prev;
	size = 0;
	median = get_median(target->prev);
	group = target->group;
	__print_stack(target->prev, A);
	printf("%d  group size = %d\n", b->group, count_stack_size(head, GROUP));
	size = count_stack_size(head, GROUP);
	while (0 < size && target->group == group)
	{
		printf("target = %ld  median = %ld head = %d  target->group = %d\n", target->data, median, head->group, group);
		if (target->data < median && head->group == -1)
			pb(a, b);
		else if (target->data > median && head->group == -2)
			pa(a, b);
		else if (head ->group == -1)
			rotate(a, A, TRUE);
		else
			rotate(b, B, TRUE);
		size--;
		target = head->next;
		printf("count = %d\n", size);
	}
}
