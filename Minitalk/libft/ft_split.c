/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:04:30 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:04:34 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordlen(char const *s, int i, char c)
{
	int	l;

	l = 0;
	while (*(s + i + l) != c && *(s + i + l))
		l++;
	return (l);
}

static char	**free_previous(char **res_start, char **result)
{
	char	**start;

	start = res_start;
	while (res_start != result)
	{
		free(*res_start);
		res_start++;
	}
	free(start);
	return (NULL);
}

static char	**create_arr(char const *s, char c)
{
	int		w;
	int		i;
	char	**result;

	if (!s)
		return (NULL);
	w = 0;
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != c && (i == 0 || (i != 0 && *(s + i - 1) == c)))
			w++;
		i++;
	}
	result = (char **) malloc((w + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[w] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	char	**res_start;

	i = 0;
	result = create_arr(s, c);
	if (!result)
		return (NULL);
	res_start = result;
	while (*(s + i))
	{
		if (*(s + i) != c && (i == 0 || (i != 0 && *(s + i - 1) == c)))
		{
			*result = ft_substr(s, i, wordlen(s, i, c));
			if (!(*result))
				return (free_previous(res_start, result));
			result++;
		}
		i++;
	}
	return (res_start);
}
