/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:10:15 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:15:17 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int    *extract_values(t_stack *stack)
{
    t_node	*current;
    int		*values;
    int		i;

    if (!stack || stack->size == 0)
        return (NULL);
    values = malloc(sizeof(int) * stack->size);
    if (!values)
        return (NULL);
    current = stack->head;
    i = 0;
    while (current)
    {
        values[i] = current->value;
        current = current->next;
        i++;
    }
    return (values);
}

//Assigns indices to nodes in descending order of their value
//takes the nbr of elements and loop until 0 - scan all nodes
//Bigger values get higher indices, small one get lower
void	assign_index(t_stack *stack_a)
{
	t_node	*current;
	int		*value;
	int		i;

	value = extract_values(stack_a);
	if (!value)
		return ;
    bubble_sort(value, stack_a->size);
    current = stack_a->head;
	while (current)
	{
        i = 0;
        while (i < stack_a->size)
        {            
            if (value[i] == current->value)
            {
                current->index = i;
                break ;
            }
			i++;
        }
        current = current->next;
	free(value);
}

