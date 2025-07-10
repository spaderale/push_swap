/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 18:16:13 by abroslav          #+#    #+#             */
/*   Updated: 2025/07/09 18:18:32 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_tokens(char *str, char delimiter)
{
	int		count;
	bool	in_token;

	count = 0;
	while (*str)
	{
		in_token = false;
		while (*str == delimiter)
			++str;
		while (*str != delimiter && *str)
		{
			if (!in_token)
			{
				++count;
				in_token = true;
			}
			++str;
		}
	}
	return (count);
}

static char		*extract_token(char *str, char delimiter)
{
	static int	cursor = 0;
	char	*token;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[cursor] == delimiter)
		++cursor;
	while ((str[cursor + len] != delimiter) && str[cursor + len])
		++len;

	token = malloc((size_t)len * sizeof(char) + 1);
	if (!token)
		return (NULL);
	while ((str[cursor] != delimiter) && str[cursor])
		token[i++] = str[cursor++];
	token[i] = '\0';
	return (token);
}

char		**split(char *str, char delimiter)
{
	int		token_count;
	char	**tokens;
	int		i;

	i = 0;
	if (!str || !*str)
		return (NULL);
	token_count = count_tokens(str, delimiter);
	if (!token_count)
		return (NULL);
	tokens = malloc(sizeof(char *) * (size_t)(token_count + 1));
	if (!tokens)
		return (NULL);
	while (i < token_count)
	{
		tokens[i] = extract_token(str, delimiter);
		if (!tokens[i])
		{
			while (i > 0)
				free(tokens[--i]);
			free(tokens);
			return (NULL);
		}
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
