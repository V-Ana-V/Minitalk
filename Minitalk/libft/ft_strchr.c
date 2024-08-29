/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:04:49 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:04:57 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;

	ch = (unsigned char) c;
	if (ch == '\0')
	{
		return ((char *)(s + ft_strlen(s)));
	}
	while (*s)
	{
		if (ch == *s)
			return ((char *) s);
		s++;
	}
	return (NULL);
}
