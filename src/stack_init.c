/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Convert str into long nbmr
static long		convert_to_long(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = result * 10 + (*str++ - '0');
	return (result * sign);
}

//Add new node to the end of the stack - Node memory allocate
static void		add_node_to_stack(t_sort_unit **stack, int value)
{
	t_sort_unit		*new_node;
	t_sort_unit		*last_node;

	new_node = malloc(sizeof(t_sort_unit));
	if (!new_node)
		handle_errors(stack);
	new_node->value = value;
	new_node->next = NULL;
	new_node->is_cheapest = false;
	if (!*stack)
	{
		*stack = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = get_last_node(*stack);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

//Initialize stack A - validate syntax and duplicates
//Change str to nbr e add node to the stack
void		initialize_stack_a(t_sort_unit **stack_a, char **input_value)
{
	long	converted_value;
	int		i;

	i = 0;
	while(input_value[i])
	{
		if (validate_number_format(input_value[i]))
			handle_errors(stack_a);
		converted_value = convert_to_long(input_value[i]);
		if (converted_value < INT_MIN || converted_value > INT_MAX)
			handle_errors(stack_a);
		if (check_duplicate_number(*stack_a, (int)converted_value))
			handle_errors(stack_a);
		add_node_to_stack(stack_a, (int)converted_value);
		i++;
	}
}

//Find the lowest push cost
t_sort_unit		*get_cheapest_node(t_sort_unit *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//Prepare the stack rotating until the node be on the top
void	prepare_for_push(t_sort_unit **stack, t_sort_unit *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->is_above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->is_above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}

	}
}

void	min_to_top(t_sort_unit **a)
{
	t_sort_unit	*min_node;

	min_node = find_smallest_value(*a);
	prepare_for_push(a, min_node, 'a');
}
