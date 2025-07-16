/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:24:22 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:26:28 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*top_b;

	if (stack_b->size == 0)
		return ;
	top_b = pop_node_top(stack_b);
	add_node_top(stack_a, top_b);
	if (print)
		ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b, int print)
{
	t_node	*top_a;

	if (stack_a->size == 0)
		return ;
	top_a = pop_node_top(stack_a);
	add_node_top(stack_b, top_a);
	if (print)
		ft_printf("pb\n");
}
