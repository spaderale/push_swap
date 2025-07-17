/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_remaining_rotations(t_stack *stack, int *cost, char stack_name)
{
	while (*cost > 0)
	{
		if (stack_name == 'a')
			ra(stack, 1);
		else if (stack_name == 'b')
			rb(stack, 1);
		(*cost)--;
	}
	while (*cost < 0)
	{
		if (stack_name == 'a')
			rra(stack, 1);
		else if (stack_name == 'b')
			rrb(stack, 1);
		(*cost)++;
	}
}

t_node	*find_cheapest_node(t_stack *stack_b)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		cheapest_total_cost;

	current = stack_b->head;
	cheapest_total_cost = INT_MAX;
	cheapest_node = NULL;
	while (current)
	{
		if (abs(current->cost_a) + abs(current->cost_b) < cheapest_total_cost)
		{
			cheapest_total_cost = abs(current->cost_a) + abs(current->cost_b);
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}

void	do_combined_rotations(t_stack *stack_a, t_stack *stack_b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(stack_a, stack_b, 1);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		(*cost_a)++;
		(*cost_b)++;
	}
}

void	execute_cheapest_move(t_stack *stack_a, t_stack *stack_b)
{
	int		cheapest_cost_a;
	int		cheapest_cost_b;
	t_node	*cheapest_node;

	cheapest_node = find_cheapest_node(stack_b);
	if (cheapest_node)
	{
		cheapest_cost_a = cheapest_node->cost_a;
		cheapest_cost_b = cheapest_node->cost_b;
		do_combined_rotations(stack_a, stack_b, &cheapest_cost_a, &cheapest_cost_b);
		do_remaining_rotations(stack_a, &cheapest_cost_a, 'a');
		do_remaining_rotations(stack_b, &cheapest_cost_b, 'b');
		pa(stack_a, stack_b, 1);
	}
}
