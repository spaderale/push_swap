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
	in_token = false;
	while (*str)
	{
		if (*str != delimiter && !in_token)
		{
			count++;
			in_token = true;
		}
		else if (*str == delimiter)
			in_token = false;
		str++;
	}
	return (count);
}

static char		*extract_token(char *str, char delimiter, int *cursor)
{
	char	*token;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (str[*cursor] == delimiter)
		(*cursor)++;
	while (str[*cursor + len] && str[*cursor + len] != delimiter)
		len++;

	token = malloc(len + 1);
	if (!token)
		return (NULL);
	while (i < len)
		token[i++] = str[(*cursor)++];
	token[i] = '\0';
	return (token);
}

char		**split(char *str, char delimiter)
{
	int		token_count;
	char	**tokens;
	int		cursor;
	int		i;

	cursor = 0;
	i = 0;
	if (!str || !*str)
		return (NULL);
	while (i < token_count)
	{
		tokens[i] = extract_token(str, delimiter, &cursor);
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
