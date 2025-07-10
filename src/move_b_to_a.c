/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:11:10 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 14:23:10 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Define a target in stack A for each node in B
//The target is the smallest value in A GREATER than the current value in B
//If none exists use the smallest value in A
static void	set_target_nodes(t_sort_unit *stack_a, t_sort_unit *stack_b)
{
	t_sort_unit		*current_a;
	t_sort_unit		*target_node;
	long			closest_value;

	while (stack_b)
	{
		closest_value = LONG_MAX;
		current_a = stack_a;
		while (current_a)
		{
			if (current_a->value > stack_b->value && current_a->value < closest_value)
			{
				closest_value = current_a->value;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_value == LONG_MAX)
			stack_b->target_node = find_smallest_value(stack_a);
		else
			stack_b->target_node = target_node;
		stack_b = stack_b->next;
	}
}

//Inicialize the data to move the node from B to A
//Update index & medians - Set the target node in A for each node in B
void	prepare_stack_b(t_sort_unit *stack_a, t_sort_unit *stack_b)
{
	update_node(stack_a);
	update_node(stack_b);
	set_target_nodes(stack_a, stack_b);
}
