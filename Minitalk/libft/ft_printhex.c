/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:42:04 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/15 10:42:08 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printhex(unsigned int nb, char c)
{
	int		count;
	char	d;
	char	*hex;
	int		re;

	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	count = 0;
	if (nb / 16 != 0)
	{
		re = ft_printhex(nb / 16, c);
		if (re == -1)
			return (-1);
		count += re;
	}
	d = hex[nb % 16];
	if (write(1, &d, 1) == -1)
		return (-1);
	count++;
	return (count);
}
