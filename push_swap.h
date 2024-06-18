/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttakino <ttakino@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 16:03:56 by ttakino           #+#    #+#             */
/*   Updated: 2024/06/17 16:58:14 by ttakino          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

 #define PUSH_SWAP_H

 #include <unistd.h>
 #include <stdlib.h>
 
typedef struct s_stack
{
	struct s_stack	*prev;
	struct s_stack	*next;
	long			data;
}	t_stack;

void	sa(t_stack *a);
void	sb(t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);



int	count_stack_size(t_stack *stack);
 
 #endif