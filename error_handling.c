/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:52:30 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/16 17:09:46 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_integer(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		i++;
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

long	long_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_duplicate(long value, t_stack *a)
{
	t_stack *target;

	target = a->next;
	while (target != a)
	{
		if (target->data == value)
			return (TRUE);
		target = target->next;
	}
	return (FALSE);
}

void	free_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

int	add_node(t_stack *head, long data)
{
	t_stack	*new;
	t_stack	*first;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (new == NULL)
		return (FALSE);
	new->data = data;
	new->group = 0;
	first = head->prev;
	new->next = head;
	new->prev = first;
	first->next = new;
	head->prev = new;
	return (TRUE);
}

int	is_error(int argc, t_stack *a, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL)
			return (TRUE);
		i++;
		j = 0;
		while (str[j] != NULL)
		{
			if (is_integer(str[j]) == FALSE)
			{
				printf("->\x1b[35m%s\x1b[m not integer\n", str[j]);
				return (free_str(str), TRUE);
			}
			if (long_atoi(str[j]) > INT_MAX || INT_MIN > long_atoi(str[j]))
			{
				printf("->\x1b[35m%s\x1b[m bigger than integer\n", str[j]);
				return (free_str(str), TRUE);
			}
			if (is_duplicate(long_atoi(str[j]), a) == TRUE)
			{
				printf("->\x1b[35m%s\x1b[m duplicates\n", str[j]);
				return (free_str(str), TRUE);
			}
			if (add_node(a, long_atoi(str[j])) == FALSE)
				return (free_str(str), TRUE);
			j++;
		}
		free_str(str);
	}
	return (FALSE);
}
