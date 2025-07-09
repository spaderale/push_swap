#include "push_swap.h"

//Move the top element of one stack to another
static void		move_top_element(t_sort_unit **dst, t_sort_unit **src)
{
	t_sort_unit		*element_to_move;

	if (!*src)
		return ;

	element_to_move = *src;
	*src = (*src)->next;

	if (*src)
		(*src)->prev = NULL;

	element_to_move->prev = NULL;

	if (!*dst)
	{
		*dst = element_to_move;
		element_to_move->next = NULL;
	}
	else
	{
		element_to_move->next = *dst;
		(*dst)->prev = element_to_move;
		*dst = element_to_move;
	}
}

//Push from B to A
void	pa(t_sort_unit **a, t_sort_unit **b, bool print)
{
	move_top_element(a, b);
	if (!print)
		ft_printf("pa\n");
}

//Push from A to B
void	pb(t_sort_unit **b, t_sort_unit **a, bool print)
{
	move_top_element(b, a);
	if (!print)
		ft_printf("pb\n");
}
