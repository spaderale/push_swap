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

char	**handle_split_error(char *s, char **result, int spaces)
{
	while (spaces > 0)
		free(result[--spaces]);
	free(result);
	free(s);
	return (NULL);
}

char	**add_token_to_result(char **result, char *token, int *spaces)
{
	result = realloc(result, sizeof(char *) * (*spaces + 1));
	if (!result)
		return (NULL);
	result[*spaces] = strdup(token);
	if (!result[*spaces])
		return (NULL);
	(*spaces)++;
	return (result);
}

int	init_split(const char *str, const char *delim, char **s, char ***result)
{
	if (!str || !delim || !*str)
		return (0);
	*s = strdup(str);
	if (!*s)
		return (0);
	*result = NULL;
	return (1);
}
