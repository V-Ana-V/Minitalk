/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:06:22 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:06:24 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	l_s;
	size_t	l_d;

	l_s = ft_strlen(src);
	if ((dstsize == 0) && (!dst))
		return (l_s);
	i = 0;
	l_d = ft_strlen(dst);
	if (dstsize < l_d + 1)
		return (dstsize + l_s);
	while (i + l_d < dstsize - 1 && i < l_s)
	{
		dst[i + l_d] = src[i];
		i++;
	}
	dst[i + l_d] = '\0';
	return (l_d + l_s);
}
