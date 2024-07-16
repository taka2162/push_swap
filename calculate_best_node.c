/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_best_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:40:48 by ttakino           #+#    #+#             */
/*   Updated: 2024/07/10 16:41:25 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	calculate_best_pos(t_stack *dark, long value)
{
	int		pos;
	int		dir;
	t_stack	*target;
	int		size;

	if (dark->next->group == dark->prev->group && value > dark->next->data)
		dir = CCW;
	else
		dir = CW;
	pos = 0;
	size = count_stack_size(dark);
	target = set_next_node(dark, dir);
	while (target->group == dark->next->group)
	{
		if (0 < dir * (value - target->data))
			break ;
		pos++;
		if (dir * (target->data - set_next_node(target, dir)->data) < 0)
			break ;
		target = set_next_node(target, dir);
	}
	pos *= dir / 3;
	if (size / 2 < abs(pos))
		pos = (size - abs(pos)) * (dir * -1 / 3);
	return (pos);
}

int	least_cost(int pos_a, int pos_b)
{
	int	min;
	int	result;

	if (pos_a < pos_b)
		min = pos_a;
	else
		min = pos_b;
	result = abs(pos_a - pos_b);
	if (0 < pos_a * pos_b)
		result += abs(min);
	return (result);
}

t_pos	set_pos(t_pos pos, int pos_b, int size, int cnt)
{
	int	pos_a;

	pos_a = cnt;
	if (abs(pos_a) > size / 2)
		pos_a = (size - abs(cnt)) * -1;
	if (least_cost(pos_a, pos_b) < least_cost(pos.a, pos.b))
	{
		pos.a = pos_a;
		pos.b = pos_b;
	}
	return (pos);
}

t_pos	choose_best_node(t_stack *light, t_stack *dark, int mark, int dir)
{
	int		size;
	int		cnt;
	t_stack	*target;
	t_pos	pos;
	t_pos	reverse;

	size = count_stack_size(light);
	pos.a = INT_MAX;
	pos.b = 0;
	cnt = (-1 + dir / 3) / 2;
	target = set_next_node(light, dir);
	while (target->group == dark->next->group)
	{
		if (dir == CCW && mark <= abs(cnt))
			break ;
		pos = set_pos(pos, calculate_best_pos(dark, target->data), size, cnt);
		cnt += dir / 3;
		target = set_next_node(target, dir);
	}
	if (dir == CW)
		reverse = choose_best_node(light, dark, size - abs(cnt), CCW);
	if (dir == CW && abs(pos.a - pos.b) > abs(reverse.a - reverse.b))
			pos = reverse;
	return (pos);
}
