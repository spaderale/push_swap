/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		init_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (!*stack)
		return (0);
	(*stack)->head = NULL;
	(*stack)->size = 0;
	return (1);
}

int	has_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

int	add_to_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = create_node(value);
	if (!new_node)
		return (0);
	add_node_bottom(stack, new_node);
	return (1);
}

int	parse_args(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			return (0);
		num = atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		if (has_duplicate(stack_a, (int)num))
			return (0);
		if (!add_to_stack(stack_a, (int)num))
			return (0);
		i++;
	}
	return (1);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_node	*current;
	t_node	*highest;
	int		value;
	int		i;

	i = stack_size;
	while (--i >= 0)
	{
		current = stack_a->head;
		value = INT_MIN;
		highest = NULL;
		while (current)
		{
			if (current->value > value && current->index == 0)
			{
				value = current->value;
				highest = current;
			}
			current = current->next;
		}
		if (highest)
			highest->index = i;
	}
}
