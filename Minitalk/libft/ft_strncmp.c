/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:08:12 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/05 12:08:15 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		uc1 = (unsigned char) s1[i];
		uc2 = (unsigned char) s2[i];
		if ((uc1 == '\0') || (uc1 != uc2))
			return (uc1 - uc2);
		i++;
	}
	return (0);
}
