/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:52:30 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/25 15:26:28 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../libft/libft.h"

static bool	is_digit_str(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (false);
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		if ((sign == 1 && INT_MAX < result)
			|| (sign == -1 && (result - 1) > INT_MAX))
			return (false);
		str++;
	}
	if (*str != '\0')
		return (false);
	return (true);
}

static bool	is_duplicate(long value, t_stack *a)
{
	t_stack	*target;

	target = a->next;
	while (target != a)
	{
		if (target->data == value)
			return (true);
		target = target->next;
	}
	return (false);
}

static void	free_str(char **str)
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

bool	is_error(t_stack *a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	while (i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (str == NULL || str[0] == NULL)
			return (true);
		i++;
		j = 0;
		while (str[j] != NULL)
		{
			if (!is_digit_str(str[j]))
				return (free_str(str), true);
			if (is_duplicate(ft_atoi(str[j]), a))
				return (free_str(str), true);
			if (!add_node(a, (long)ft_atoi(str[j])))
				return (free_str(str), true);
			j++;
		}
		free_str(str);
	}
	return (false);
}
