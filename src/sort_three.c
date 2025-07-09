#include "push_swap.h"

void	sort_three(t_sort_unit **stack)
{
	t_sort_unit		*max_node;

	max_node = find_largest_value(*stack);

	//Maior valor esta no topo
	if (max_node == *stack)
		ra(stack, false);
	//Maior valor esta no meio
	else if ((*stack)->next == max_node)
		rra(stack, false);
	//Verifica se ainda precisa swap
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}
