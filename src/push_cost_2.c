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

//If nmbr from B is bigger then all in A we find the smallest idx in A nd target
static void	get_smallest_as_target(t_stack *stack_a, int *target_pos)
{
	t_node	*current;
	int		smallest_index;
	int		smallest_pos;

	current = stack_a->head;
	smallest_index = INT_MAX;
	smallest_pos = 0;
	while (current)
	{
		if (current->index < smallest_index)
		{
			smallest_index = current->index;
			smallest_pos = current->position;
		}
		current = current->next;
	}
	*target_pos = smallest_pos;
}

//Looks for the smallest idx in A thats still bigger than B indx
//If it finds nothing (bcse B indx is bigger than evrthng in A) calls g_s_t fctn
static void	get_target_for_b(t_stack *stack_a, t_node *current_b, int *target_index, int *target_pos)
{
	t_node	*current_a;

	current_a = stack_a->head;
	while (current_a)
	{
		if (current_a->index > current_b->index && current_a->index < *target_index)
		{
			*target_index = current_a->index;
			*target_pos = current_a->position;
		}
		current_a = current_a->next;
	}
	if (*target_index == INT_MAX)
		get_smallest_as_target(stack_a, target_pos);
}

//Loops through each no in B - For each one it figures out where it should go in A
//Fills the target_pos field of every node in B
void	get_target_position(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_b;
	int		target_index;
	int		target_pos;

	current_b = stack_b->head;
	while (current_b)
	{
		target_index = INT_MAX;
		target_pos = 0;
		get_target_for_b(stack_a, current_b, &target_index, &target_pos);
		current_b->target_pos = target_pos;
		current_b = current_b->next;
	}
}


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

//If cost_a and cost_b are pos. use rr
//if both are neg. use rrr
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

//Picks the node from B with lowest move cost after combined rotat.
//Then pushing to A using 'pa'
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
