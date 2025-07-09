/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:28:25 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:29:31 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		perform_rotation(t_sort_unit **stack)
{
	t_sort_unit		*last_node;

	if (!*stack || !(*stack)->next)
		return ;

	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_sort_unit **a, bool print)
{
	perform_rotation(a);
	if (!print)
		ft_printf("ra\n");
}

void	rb(t_sort_unit **b, bool print)
{
	perform_rotation(b);
	if (!print)
		ft_printf("rb\n");
}

void	rr(t_sort_unit **a, t_sort_unit **b, bool print)
{
	perform_rotation(a);
	perform_rotation(b);
	if (!print)
		ft_printf("rr\n");
}
