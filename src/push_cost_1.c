/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Assigns an index-based pos. to each node at the stack
//To compute how far a node is from the top so u knw the cheapest 'ra' r 'rra' 
void	get_positions(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	current = stack->head;
	while (current)
	{
		current->position = i;
		current = current->next;
		i++;
	}
}

//Bring a node in B to top of A and its target pos in A to the top of stack
void	calculate_cost(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	int		size_a;
	int		size_b;

	size_a = get_stack_size(stack_a);
	size_b = get_stack_size(stack_b);
	current_b = stack_b->head;
	while (current_b)
	{
		current_b->cost_b = current_b->position;
		if (current_b->position > size_b / 2)
			current_b->cost_b = -(size_b - current_b->position);
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = -(size_a - current_b->target_pos);
		current_b = current_b->next;
	}
}
