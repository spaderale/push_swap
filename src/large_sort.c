/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	shift_stack(t_stack *stack_a)
{
	int	min_pos;
	int	stack_size;

	stack_size = get_stack_size(stack_a);
	min_pos = get_min_index_position(stack_a);
	if (min_pos <= stack_size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, 1);
			min_pos--;
		}
	}
	else
	{
		while (min_pos < stack_size)
		{
			rra(stack_a, 1);
			min_pos++;
		}
	}
}

static void	push_all_but_three(t_stack *stack_a, t_stack *stack_b)
{
	int		stack_size;
	int		pushed;
	int		i;

	stack_size = get_stack_size(stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 3 && i < stack_size && pushed < stack_size - 3)
	{
		if (stack_a->head->index <= stack_size - 3)
		{
			pb(stack_a, stack_b, 1);
			pushed++;
		}
		else
			ra(stack_a, 1);
		i++;
	}
	while (get_stack_size(stack_a) > 3)
		pb(stack_a, stack_b, 1);
}

void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	push_all_but_three(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		get_positions(stack_a);
		get_positions(stack_b);
		get_target_position(stack_a, stack_b);
		calculate_cost(stack_a, stack_b);
		execute_cheapest_move(stack_a, stack_b);
	}
	get_positions(stack_a);
	shift_stack(stack_a);
}
