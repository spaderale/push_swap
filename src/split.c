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

char	**handle_split_error(char **result, int count)
{
	free_split_result(result, count);
	return (NULL);
}

char	**add_token_to_result(char **result, char *token, int *spaces)
{
	//result = realloc(result, sizeof(char *) * (*spaces + 1));
	char 	**new_result;
	int		i;

	new_result = malloc(sizeof(char *) * (*spaces + 1));
	if (!new_result)
		return (NULL);

	i = 0;
	while (i < *spaces)
	{
		new_result[i] = result[i];
		i++;
	}
	new_result[*spaces] = ft_strdup(token);
	if (!new_result[*spaces])
	{
		free(new_result);
		return (NULL);
	}
	free(result);
	(*spaces)++;
	return (new_result);
}

int	init_split(const char *str, const char *delim, char **s, char ***result)
{
	if (!str || !delim || !*str)
		return (0);
	*s = ft_strdup(str);
	if (!*s)
		return (0);
	*result = NULL;
	return (1);
}

char	**split_string(const char *str, const char *delim, int *count)
{
	char	**result;
	int		i;

	(void)delim; // Não será mais usado, já que ft_split usa apenas um caractere
	
	if (!str || !*str)
		return (NULL);
	
	result = ft_split(str, ' '); // Usando ft_split diretamente
	if (!result)
		return (NULL);
	
	// Contar quantos tokens válidos temos
	i = 0;
	while (result[i])
		i++;
	*count = i;
	
	return (result);
}