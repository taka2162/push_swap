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

void	push_to_dark(t_stack **light, t_stack *dark, int group, int dir)
{
	set_next_node(*light, dir)->group = group + 1;
	if (dir == CCW)
		r_rotate(*light, TRUE);
	push(*light, dark);
}

void	divide_group(t_stack *light, t_stack *dark, int group, int dir)
{
	t_stack	*target;
	long	median;
	int		size;

	target = set_next_node(light, dir);
	median = get_median(light, dir);
	size = count_group_size(light, dir);
	while (size-- > 0)
	{
		if (target->data < median && light->group == A)
			push_to_dark(&light, dark, group, dir);
		else if (target->data >= median && light->group == B)
			push_to_dark(&light, dark, group, dir);
		else
		{
			if (dir == CW)
				rotate(light, TRUE);
			else
				r_rotate(light, TRUE);
		}
		target = set_next_node(light, dir);
	}
}

void	sort_one_or_two(t_stack *light, t_stack *dark, int size, int dir)
{
	if (dir == CCW)
	{
		r_rotate(light, TRUE);
		if (size >= 2)
			r_rotate(light, TRUE);
	}
	if (light->group == A && size == 2
		&& light->next->data > light->next->next->data)
		swap(light, TRUE);
	else if (light->group == B)
	{
		if (light->next->data < light->next->next->data && size == 2)
			swap(light, TRUE);
		push(light, dark);
		if (2 <= size)
			push(light, dark);
	}
}

int	sort_light(t_stack *light, t_stack *dark, int *group, int dir)
{
	int	flag;
	int	size;

	flag = FALSE;
	size = count_group_size(light, dir);
	if (size <= 2)
	{
		// printf("sort_one_or_two\n");
		sort_one_or_two(light, dark, size, dir);
	}
	else if (size <= 9)
	{
		// printf("extreme_sort\n");
		flag = extreme_sort(light, dark, *group, dir);
	}
	else if (size <= 365 && light->group == A)
	{
		// printf("insertion_sort\n");
		insertion_sort(light, dark, *group, FALSE);
		(*group)++;
	}
	else
	{
		// printf("divide_group\n");
		divide_group(light, dark, *group, dir);
		flag = TRUE;
	}
	return (flag);
}

void	quick_sort(t_stack *light, t_stack *dark, int group)
{
	int	dir;
	int	flag;

	dir = set_dir(light);
		//printf("\x1b[31mbefore____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// //printf("flag = %d\n", flag);
	// //printf("\x1b[32msize = %d\n", size);
	//printf("__________________________|\x1b[m\n");
	flag = sort_light(light, dark, &group, dir);
		//printf("\x1b[32mafter____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// //printf("flag = %d\n", flag);
	// //printf("\x1b[32msize = %d\n", size);
	//printf("__________________________|\x1b[m\n");
	if (light->next == light || dark->next == dark)
		return ;
	if (light->group == A)
	{
		if (flag == TRUE)
			quick_sort(light, dark, group + 1);
		else
			quick_sort(dark, light, group);
	}
	else if (light->group == B)
	{
		if (flag == TRUE)
			quick_sort(dark, light, group + 1);
		else
			quick_sort(light, dark, group);
	}
}

	// //printf("\x1b[32mafter____________________\n");
	// __print_stack(light);
	// __print_stack(dark);
	// //printf("flag = %d\n", flag);
	// //printf("\x1b[32msize = %d\n", size);
	// //printf("__________________________|\x1b[m\n");
