#include "push_swap.h"

static int	get_highest(t_stack *stack)
{
	int		highest;
	t_node	*current;

	if (!stack->head)
		return (0);
	highest = stack->head->index;
	current = stack->head->next;
	while (current)
	{
		if (current->index > highest)
			highest = current->index;
		current = current->next;
	}
	return (highest);
}

void	sort_three(t_stack *stack_a)
{
	int		highest;

	if (is_sorted(stack_a))
		return ;
	highest = get_highest(stack_a);
	if (stack_a->head->index == highest)
		ra(stack_a, 1);
	else if (stack_a->head->next->index == highest)
		rra(stack_a, 1);
	if (stack_a->head->index > stack_a->head->next->index)
		sa(stack_a, 1);
}
