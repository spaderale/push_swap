#include "push_swap.c"

//Verify if its have only validate numbers and maybe one sign before (+/-)

int		validate_number_format(char *strnbr)
{
	if (!(*strnbr == '+' || *strnbr == '-' || (*strnbr >= '0' || *strnbr <= '9')))
		return (1);
	if ((*strnbr == '+' || *strnbr == '-') && !(*strnbr[1] >= '0' || *strnbr[1] <= '9'))
		return (1);
	while (*++strnbr)
	{
		if (!(*strnbr >= '0' && *strnbr <= '9'))
			return (1);
	}
	return (0);
}

//Verify if already exists a duplicate number at the stack
int		check_duplicate_number(t_sort_unit *stack, int num)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->value == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

//Free all memory allocated
void	free_stack_memory(t_sort_unit **stack)
{
	t_sort_unit		*temp;
	t_sort_unit		*current;

	if(!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		current->value = 0;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	handle_errors(t_sort_unit **stack)
{
	free_stack_memory(stack);
	ft_printf("Error\n");
	exit(1);
}
