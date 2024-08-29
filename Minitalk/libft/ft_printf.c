/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:41:25 by avelikan          #+#    #+#             */
/*   Updated: 2024/01/15 10:41:29 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_fsp(char fsp, va_list args)
{
	if (fsp == 'c')
		return (ft_printchar(va_arg(args, int)));
	else if (fsp == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (fsp == 'p')
		return (ft_printp(va_arg(args, void *)));
	else if (fsp == 'd' || fsp == 'i')
		return (ft_printint(va_arg(args, int)));
	else if (fsp == 'u')
		return (ft_printud(va_arg(args, unsigned int)));
	else if (fsp == 'x' || fsp == 'X')
		return (ft_printhex(va_arg(args, unsigned int), fsp));
	else
		return (ft_printchar(fsp));
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		re;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			re = print_fsp(*(str + 1), args);
			str++;
		}
		else
			re = ft_printchar(*str);
		if (re < 0)
			return (-1);
		count += re;
		if (*str == '\0')
			break ;
		str++;
	}
	va_end(args);
	return (count);
}
