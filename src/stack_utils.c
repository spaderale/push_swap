#include "push_swap.h"

//Display for debug
void	display_stack_content(t_sort_unit *stack)
{
	while (stack) {
		ft_printf("%d ", stack->value);
		stack = stack->next;
	}
	ft_printf("\n");
}

//Check if a node is in the correct position in the sorted stack
bool	node_in_sorted_position(t_sort_unit *stack, t_sort_unit *node)
{
	if (node->value < find_smallest_value(stack)->value || 
		node->value > find_largest_value(stack)->value)
		return (true);
	return (false);
}

//Calculate the current stack size
int		stack_len(t_sort_unit *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

//Find the last node
t_sort_unit		*get_last_node(t_sort_unit *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

//Check if the stack is sorted
bool	is_stack_sorted(t_sort_unit *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//Find the smallest value node
t_sort_unit		*find_smallest_value(t_sort_unit *stack)
{
	long			min_value;
	t_sort_unit		*min_node;

	min_value = LONG_MAX;
	min_node = NULL;
	while (stack)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_sort_unit		*find_largest_value(t_sort_unit *stack)
{
	long			max_value;
	t_sort_unit		*max_node;

	max_value = LONG_MIN;
	*max_node = NULL;

	while (stack)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

