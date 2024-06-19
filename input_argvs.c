/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_argvs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:15:05 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/19 17:29:41 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	add_node(t_stack *head, long data)
{
	t_stack	*new;
	t_stack	*first;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		exit(1);
	new->data = data;
	first = head->next;
	new->next = head->next;
	new->prev = head;
	first->prev = new;
	head->next = new;
}

void	input_argvs(t_stack *a, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		add_node(a, (long)ft_atoi(argv[i]));
		i++;
	}
}