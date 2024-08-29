/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:09:16 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:09:18 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		start;
	int		end;
	int		l;

	if ((!s1) || (!set))
		return (0);
	start = 0;
	end = 0;
	l = ft_strlen(s1);
	while (*(s1 + start) && in_set(*(s1 + start), set))
		start++;
	while (l - start - end > 0 && in_set(*(s1 + l - 1 - end), set))
		end++;
	result = malloc(l - end - start + 1);
	if (!result)
		return (0);
	ft_strlcpy(result, s1 + start, l - end - start + 1);
	return (result);
}
