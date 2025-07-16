/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:26:46 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:28:11 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*first;
	t_node	*last;

	if (stack->size < 2)
		return ;
	first = stack->head;
	last = first;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->head = last;
}

void	rra(t_stack *stack_a, int print)
{
	reverse_rotate(stack_a);
	if (print)
		ft_printf("rra\n");
}

void	rrb(t_stack *stack_b, int print)
{
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b, int print)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (print)
		ft_printf("rrr\n");
}
