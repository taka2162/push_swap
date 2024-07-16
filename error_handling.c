/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:52:30 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/16 16:56:48 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_duplicate(long value, long *save, int indx)
{
	int	i;

	i = 0;
	while (i < indx)
	{
		if (save[i] == value)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	is_error(int argc, char **argv)
{
	int		i;
	long	*save;

	save = (long *)malloc((argc - 1) * sizeof(long));
	if (save == NULL)
		return (FALSE);
	// save[argc - 1] = (long)NULL;
	i = 1;
	while (i < argc)
	{
		if (is_integer(argv[i]) == FALSE)
		{
			printf("not integer\n");
			return (free(save), TRUE);
		}
		if (long_atoi(argv[i]) > INT_MAX || INT_MIN > long_atoi(argv[i]))
		{
			printf("bigger than integer\n");
			return (free(save), TRUE);
		}
		if (is_duplicate(long_atoi(argv[i]), save, i) == TRUE)
		{
			printf("duplicates\n");
			return (free(save), TRUE);
		}
		save[i - 1] = long_atoi(argv[i]);
		i++;
	}
	free(save);
	return (FALSE);
}
