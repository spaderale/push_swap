/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:10:15 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:17 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Starts with min_index = INT_MAX to ensure anythgn smaller replaces it
//Iterates all nodes and update if current nodes indx is smaller
int	get_min_index_position(t_stack *stack)
{
	t_node	*current;
	int		min_index;
	int		min_pos;

	if (!stack->head)
		return (-1);
	current = stack->head;
	min_index = INT_MAX;
	min_pos = 0;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = current->position;
		}
		current = current->next;
	}
	return (min_pos);
}

int	get_max_index_position(t_stack *stack)
{
	t_node	*current;
	int		max_index;
	int		max_pos;

	if (!stack->head)
		return (-1);
	current = stack->head;
	max_index = -1;
	max_pos = 0;
	while (current)
	{
		if (current->index > max_index)
		{
			max_index = current->index;
			max_pos = current->position;
		}
		current = current->next;
	}
	return (max_pos);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack->head || !stack->head->next)
		return (1);
	current = stack->head;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
