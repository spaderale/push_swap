#include "push_swap.h"

static int	process_numbers(char **numbers, int count, t_stack *stack_a, int *has_numbers)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_int(numbers[i]) || has_duplicate(stack_a, atol(numbers[i])))
		{
			free_split_result(numbers, count);
			return (0);
		}
		add_node_bottom(stack_a, create_node(atol(numbers[i])));
		*has_numbers = 1;
		i++;
	}
	return (1);
}

int	parse_and_fill_stack(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		count;
	char	**numbers;
	int		has_numbers;

	i = 1;
	has_numbers = 0;
	while (i < argc)
	{
		if (!argv[i][0] || !is_number(argv[i]))
			return (0);
		numbers = split_string(argv[i], " ", &count);
		if (!numbers || count == 0)
			return (0);
		if (!process_numbers(numbers, count, stack_a, &has_numbers))
			return (0);
		free_split_result(numbers, count);
		i++;
	}
	return (has_numbers);
}
