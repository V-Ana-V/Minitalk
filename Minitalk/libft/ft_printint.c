/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:42:36 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/15 10:42:39 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	handle_minus(int *nb)
{
	if (*nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		*nb = -(*nb);
		return (1);
	}
	return (0);
}

int	ft_printint(int nb)
{
	int	count;
	int	d;
	int	re;

	count = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	count += handle_minus(&nb);
	if (count == -1)
		return (-1);
	if (nb / 10 != 0)
	{
		re = ft_printint(nb / 10);
		if (re == -1)
			return (-1);
		count += re;
	}
	d = nb % 10 + 48;
	if (write(1, &d, 1) == -1)
		return (-1);
	count++;
	return (count);
}
