/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:52:30 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/21 19:24:07 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	is_integer(const char *nptr)
{
	int		sign;
	long	result;

	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	result = 0;
	while ('0' <= *nptr && *nptr <= '9')
	{
		result = result * 10 + (*nptr - '0');
		if ((sign == 1 && INT_MAX < result)
			|| (sign == -1 && result - 1 > INT_MAX))
			return (FALSE);
		nptr++;
	}
	return (TRUE);
}

int	is_digit_str(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		i++;
	}
	if (i == 0 || is_integer(str) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	is_duplicate(long value, t_stack *a)
{
	t_stack	*target;

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

int	is_error(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL || str[0] == NULL)
			return (TRUE);
		i++;
		j = 0;
		while (str[j] != NULL)
		{
			if (is_digit_str(str[j]) == FALSE)
				return (free_str(str), TRUE);
			if (is_duplicate(is_digit_str(str[j]), a) == TRUE)
				return (free_str(str), TRUE);
			if (add_node(a, (long)ft_atoi(str[j])) == FALSE)
				return (free_str(str), TRUE);
			j++;
		}
		free_str(str);
	}
	return (FALSE);
}
