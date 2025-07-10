/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:31:20 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 15:04:13 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Rotate A & B at the same time until the A cheapest node be on the top
//and the target node in B be on the top - update index after rotation
static void	rot_both(t_sort_unit **a, t_sort_unit **b, t_sort_unit *cheap_node)
{
	while (*b != cheap_node->target_node && * != cheap_node)
		rra(a, b, false);
	update_node(*a);
	update_node(*b);
}

//Reverse rotate A and B until the A cheapest node be on the top
//and the B atrget node be on the top
static void	rev_rot_both(t_sort_unit **a, t_sort_unit **b, t_sort_unit *cheap_node)
{
	while (*b != cheap_node->target_node && *a != cheap_node)
		rrr(a, b, false);
	update_node(*a);
	update_node(*b);
}

//Move the cheap node from A to B - rotate ou reverse depending the node position
static void	move_a_to_b(t_sort_unit **a, t_sort_unit **b)
{
	t_sort_unit		*cheapest_node;

	cheapest_node = get_cheapest_node(*a);
	if (!cheapest_node)
	{
		pb(b, a, false);
		return ;
	}
	if (cheapest_node->is_above_median && cheapest_node->target_node->is_above_median)
		rot_both(a, b, cheapest_node);
	else if (!cheapest_node->is_above_median && !cheapest_node->target_node->is_above_median)
		rev_rot_both(a, b, cheapest_node);
	prepare_for_push(a, cheapest_node 'a');
	pb(b, a, false);
}

static void	move_b_to_a(t_sort_unit **a, t_sort_unit **b)
{
	prepare_for_push(a, (*b)->target_node, 'a');
	pa(a, b, false);
}

static void	min_to_top(t_sort_unit **a)
{
	t_sort_unit	*min_node;

	min_node = find_smallest_value(*a);
	while (*a != min_node)
	{
		if (min_node->is_above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}

//Turk algorithm
void	sort_stacks(t_sort_unit **a, t_sort_unit **b)
{
	int	len_a;

	len_a = stack_len;
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	if (len_a-- > 3 && !is_stack_sorted(*a))
		pb(b, a, false);
	while (len_a-- > 3 && !is_stack_sorted(*a))
	{
		prepare_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		prepare_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	min_to_top(a);
}
