/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Prepares memory and structure for both stacks before any parsing or operat.
void	setup_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (!init_stack(stack_a) || !init_stack(stack_b))
	{
		ft_printf("Error\n");
		exit(1);
	}
}

static void	do_sorting(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	if (!is_sorted(stack_a))
	{
		if (stack_size == 2)
			sa(stack_a, 1);
		else if (stack_size == 3)
			sort_three(stack_a);
		else
			sort_large(stack_a, stack_b);
	}
}

/*int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!init_stack(&stack_a) || !init_stack(&stack_b))
	{
		ft_printf("Error\n");
		return (1);
	}
	if (!parse_and_fill_stack(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		ft_printf("Error\n");
		return (1);
	}
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a);
	if (!is_sorted(stack_a))
		do_sorting(stack_a, stack_b, stack_size);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}*/
