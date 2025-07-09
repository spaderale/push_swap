#include "push_swap.h"

//Swap the first two elements of a stack
//
//
//
static void		perform_swap(t_sort_unit **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;

	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

//Swap the firs two elements of stack A
void	sa(t_sort_unit **a, bool print)
{
	perform_swap(a);
	if (!print)
		ft_printf("sa\n");
}

//Swap the first two of stack B
void	sb(t_sort_unit **b, bool print)
{
	perform_swap(b);
	if (!print)
		ft_printf("sb\n");
}

//Swap both stacks simultaneosly
void	ss(t_sort_unit **a, t_sort_unit **b, bool print)
{
	perform_swap(a);
	perform_swap(b);
	if (!print)
		ft_printf("ss\n");
}
