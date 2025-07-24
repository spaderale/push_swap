/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:16:13 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:18:32 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split_result(char **tokens, int count)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (i < count)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

char	**add_token_to_result(char **tokens, char *new_token, int *count)
{
	char	**new_array;
	int		i;

	if (!tokens || !new_token || !count || *count < 0)
		return (NULL);
	new_array = malloc(sizeof(char *) * (*count + 1));
	if (!new_array)
		return (NULL);
	i = 0;
	while (i < *count)
	{
		new_array[i] = tokens[i];
		i++;
	}
	new_array[*count] = ft_strdup(new_token);
	if (!new_array[*count])
	{
		free(new_array);
		return (NULL);
	}
	free(tokens);
	*count = *count + 1;
	return (new_array);
}

char	**split_string(const char *str, int *count)
{
	char	**result;
	int		i;

	if (!str || !*str)
		return (NULL);
	result = ft_split(str, ' ');
	if (!result)
		return (NULL);
	i = 0;
	while (result[i])
		i++;
	*count = i;
	return (result);
}
