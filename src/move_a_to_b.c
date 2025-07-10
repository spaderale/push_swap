/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 21:56:15 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:46:31 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Update the position and status of each node in the stack
//Index: current position in the stack (0 = top)
void	update_node(t_sort_unit *stack)
{
	int		idx;
	int		median;

	idx = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_index = idx;
		if (idx <= median)
			stack->is_above_median = true;
		else
			stack->is_above_median = false;
		stack = stack->next;
		idx++;
	}
}

//Define a target in stack B for each node in stack A
//The target is the largest value in B less then the atual value in A
//If A value is less then all in B so use the largest value in B
static void		set_target_nodes(t_sort_unit *stack_a, t_sort_unit *stack_b)
{
	t_sort_unit		*current_b;
	t_sort_unit		*target_node;
	long			closest_value;

	while (stack_a)
	{
		closest_value = LONG_MIN;
		current_b = stack_b;
		while(current_b)
		{
			if (current_b->value < stack_a->value && current_b->value > closest_value)
			{
				closest_value = current_b->value;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_value == LONG_MIN)
			stack_a->target_node = find_largest_value(stack_b);
		else
			stack_a->target_node = target_node;
		stack_a = stack_a->next;
	}
}

//Calculate the cost to move each node (Rotations to take the node to the top & target)
//They are ajusted if the node ou target are above the median line
static void	calculate_push_cost(t_sort_unit *stack_a, t_sort_unit *stack_b)
{
	int		size_a;
	int		size_b;

	size_a = stack_len(stack_a);
	size_b = stack_len(stack_b);
	while (stack_a)
	{
		stack_a->push_cost = stack_a->current_index;
		if (!stack_a->is_above_median)
			stack_a->push_cost = size_a - stack_a->current_index;
		if (stack_a->target_node->is_above_median)
			stack_a->push_cost += stack_a->target_node->current_index;
		else
			stack_a->push_cost += size_b - stack_a->target_node->current_index;
		stack_a = stack_a->next;
	}
}

//Set the node with the smallest cost
void	mark_cheapest_node(t_sort_unit *stack)
{
	long			lowest_cost;
	t_sort_unit		*cheapest_node;

	if (!stack)
		return ;
	lowest_cost = LONG_MAX;
	cheapest_node = stack;
	while (stack)
	{
		stack->is_cheapest = false;
		if (stack->push_cost < lowest_cost)
		{
			lowest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

//Inicialize the data to move the node from A to B
//Update indez e median - Set target in B - Calculate costs - Mark the cheapest node
void	prepare_stack_a(t_sort_unit *stack_a, t_sort_unit *stack_b)
{
	update_node(stack_a);
	update_node(stack_b);
	set_target_nodes(stack_a, stack_b);
	calculate_push_cost(stack_a, stack_b);
	mark_cheapest_node(stack_a);
}
