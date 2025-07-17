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

int	get_stack_size(t_stack *stack)
{
	return (stack->size);
}

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

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack)
		return ;
	current = stack->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	free(stack);
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

void	exit_eror(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_printf("Error\n");
	exit(1);
}
