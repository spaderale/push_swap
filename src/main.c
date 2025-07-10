/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:22:09 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:30:15 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_input(int argc, char **argv, t_sort_unit **stack_a)
{
	char	**tokens;
	int		i;

	if (argc == 2)
	{
		tokens = split(argv[1], ' ');
		if (!tokens)
			handle_errors(stack_a);
		initialize_stack_a(stack_a, tokens);
		i = 0;
		while (tokens[i]){
			free(tokens[i]);
			i++;
		}
		free(tokens);
	}
	else
		initialize_stack_a(stack_a, argv + 1);
}

int	main(int argc, char **argv)
{
	t_sort_unit		*stack_a;
	t_sort_unit		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	process_input(argc, argv, &stack_a);
	if (!is_stack_sorted(stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a, false);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort_stacks(&stack_a, &stack_b);
	}
	free_stack_memory(&stack_a);
	return (0);
}
