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
	int	i;

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

/*Free a split result array and its contents
char	**handle_split_error(char **result, int count)
{
	free_split_result(result, count);
	return (NULL);
}

void	free_split_result(char **result, int count)
{
	int	i;

	if (!result)
		return ;
	i = 0;
	while (i < count)
		free(result[i++]);
	free(result);
}

char	**add_token_to_result(char **result, char *token, int *spaces)
{
	if (!result || !token || !spaces || *spaces < 0)
		return (NULL);	
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
}*/
