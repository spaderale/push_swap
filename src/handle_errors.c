/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:06:36 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/10 16:36:49 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

//Centralized function to free memory 
void	exit_error(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	ft_printf("Error\n");
	exit(1);
}

//Return the absolute avlue of an integer
//Useful for cost calculations - cost_a & cost_b
int	abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
