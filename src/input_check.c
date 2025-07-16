#include "push_swap.h"

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
}

static long	check_overflow(long result, char digit, int sign)
{
	if (result > LONG_MAX / 10 || (result == LONG_MAX / 10 && digit - '0' > LONG_MAX % 10))
	{
		if (sign == 1)
			return (LONG_MAX);
		else
			return (LONG_MIN);
	}
	return (result * 10 + (digit - '0'));
}

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

int		abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
