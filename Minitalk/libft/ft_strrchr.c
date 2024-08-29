/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:08:56 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:09:00 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	int		l;
	int		i;

	l = ft_strlen(s);
	i = 0;
	ch = (unsigned char) c;
	while (i <= l)
	{
		if (ch == *(s + l - i))
			return ((char *)(s + l - i));
		i++;
	}
	return (NULL);
}
