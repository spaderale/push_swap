#include "push_swap.h"


//Last element go to the top
static void		reverse_rotate(t_sort_unit **stack)
{
	t_sort_unit		*last_node;
	if (!*stack || !(*stack)->next)
		return ;

	last_node = get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_sort_unit **a, bool print)
{
	reverse_rotate(a);
	if (!print)
		ft_printf("rra\n");
}

void	rrb(t_sort_unit **b, bool print)
{
	reverse_rotate(b);
	if (!print)
		ft_printf("rrb\n");
}

void	rrr(t_sort_unit **a, t_sort_unit **b, bool print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!print)
		ft_printf("rrr\n");
}
