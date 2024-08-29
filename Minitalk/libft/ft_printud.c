/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printud.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:43:54 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/15 10:43:57 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printud(unsigned int nb)
{
	char			count;
	unsigned int	d;
	int				re;

	count = 0;
	if (nb / 10 != 0)
	{
		re = ft_printud(nb / 10);
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
