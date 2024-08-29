/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:43:31 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/15 10:43:34 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printstr(char *s)
{
	ssize_t	re;
	int		i;

	if (!s)
	{
		re = write(1, "(null)", 6);
		if (re == -1)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
	{
		re = write(1, s + i++, 1);
		if (re == -1)
			return (-1);
	}
	return (i);
}
