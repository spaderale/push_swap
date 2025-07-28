/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:37:35 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:45:45 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Prevents invalid or overflowing valuew from being processed or pushed
int	is_valid_int(const char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num = num * 10 + (str[i] - '0');
		if ((str[0] != '-' && num > INT_MAX)
			|| (str[0] == '-' && num > ((long)INT_MAX + 1)))
			return (0);
		i++;
	}
	return (1);
}

/*Catch no-numeric inputs before attempting conversion
int	is_number(char *str)
{
	int	i;
	int	digit_found;

	i = 0;
	digit_found = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			digit_found = 1;
		else
			return (0);
		i++;
	}
	return (digit_found);
}*/

int	has_duplicate(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->head;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

//Prevents integers overflow when converting a string to a number
//custom atol to safely grow the result number during parsing

static long	check_overflow(long result, char digit, int sign)
{
	if (result > LONG_MAX / 10
		|| (result == LONG_MAX / 10 && digit - '0' > LONG_MAX % 10))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (result * 10 + (digit - '0'));
}

//Skips any space - Check for sign - convert numeric char to a long value

long	atol(const char *str)
{
	long	result;
	int		sign;
	int		i;
	long	temp;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = check_overflow(result, str[i], sign);
		if (temp == LONG_MAX || temp == LONG_MIN)
			return (temp);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
