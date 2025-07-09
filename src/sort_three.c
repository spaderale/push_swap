/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:31:53 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:33:10 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_sort_unit **stack)
{
	t_sort_unit		*max_node;

	max_node = find_largest_value(*stack);

	if (max_node == *stack)
		ra(stack, false);
	else if ((*stack)->next == max_node)
		rra(stack, false);
	if ((*stack)->value > (*stack)->next->value)
		sa(stack, false);
}
