/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//If the stack is empty the new_node becomes the head
//Or look for the last node and links the new_node after it
void	add_node_bottom(t_stack *stack, t_node *new_node)
{
	t_node	*last;

	if (!stack->head)
		stack->head = new_node;
	else
	{
		last = stack->head;
		while (last->next)
			last = last->next;
		last->next = new_node;
		new_node->prev = last;
	}
	stack->size++;
}

//If its empty the new_node becomes the head or link it before the current head
//'pa' - 'pb' - where push a node to the top
void	add_node_top(t_stack *stack, t_node *new_node)
{
	if (!stack->head)
		stack->head = new_node;
	else
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	stack->size++;
}

//Remove and return the top node from the stack
t_node	*pop_node_top(t_stack *stack)
{
	t_node	*top;

	if (!stack->head)
		return (NULL);
	top = stack->head;
	if (top->next)
	{
		stack->head = top->next;
		stack->head->prev = NULL;
		top->next = NULL;
	}
	else
		stack->head = NULL;
	stack->size--;
	return (top);
}
