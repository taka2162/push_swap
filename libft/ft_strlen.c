/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 11:50:20 by ttakino           #+#    #+#             */
/*   Updated: 2024/04/29 17:52:45 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

// #include <stdio.h>
// int	main(int argc, char** argv)
// {
// 	if (argc != 2)
// 		return (0);
// 	printf("%d\n", ft_strlen(argv[1]));
// 	return (0);
// }