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

static void	bubble_sort(int *arr, int size)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

//Assigns indices to nodes in descending order of their value
//takes the nbr of elements and loop until 0 - scan all nodes
//Bigger values get higher indices, small one get lower
void	assign_index(t_stack *stack_a)
{
	t_node	*current;
	int		size;
	int		*value;
	int		i;

	size = stack_a->size;
	value = malloc(sizeof(int) * size);
	if (!value)
		return ;
	current = stack_a->head;
	i = 0;
	while (current)
	{
		value[i] = current->value;
		current = current->next;
		i++;
	}
	bubble_sort(value, size);
	current = stack_a->head;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (value[i] == current->value)
			{
				current->index = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
	free(value);
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

/*void    assign_index(t_stack *stack_a, int stack_size)
{
    t_node  *current;
    t_node  *highest;
    int     value;
    int     i;

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
}*/
