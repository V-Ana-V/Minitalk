/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:09:29 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:09:32 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_sub;
	size_t	s_len;
	size_t	tail;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	tail = 0;
	if (start < s_len)
		tail = s_len - start;
	if (tail > len)
		tail = len;
	s_sub = (char *) malloc((tail + 1) * sizeof(char));
	if (!s_sub)
		return (NULL);
	if (start >= s_len)
	{
		*s_sub = '\0';
		return (s_sub);
	}
	ft_strlcpy(s_sub, s + start, tail + 1);
	return (s_sub);
}
