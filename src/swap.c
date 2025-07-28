/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c  			                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:29:59 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:30:26 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Adjust pointers so second becomes the new head
static void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;
	if (second->next)
		second->next->prev = first;
	first->next = second->next;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	stack->head = second;
}

void	sa(t_stack *stack_a, int print)
{
	swap(stack_a);
	if (print)
		ft_printf("sa\n");
}

void	sb(t_stack *stack_b, int print)
{
	swap(stack_b);
	if (print)
		ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap(stack_a);
	swap(stack_b);
	if (print)
		ft_printf("ss\n");
}
