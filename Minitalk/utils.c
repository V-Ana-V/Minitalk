/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:58:15 by avelikan          #+#    #+#             */
/*   Updated: 2024/08/13 14:58:19 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_character(int signal)
{
	static unsigned char	c = 0;
	static int	count = 0;

	c = c << 1;
	if (signal == SIGUSR1)
		c = c | 1;
	if (signal == SIGUSR2)
		c = c | 0;
	count++;
	if (count == 8)
	{
		count = 0;
		write(1, &c, 1);
		c = 0;
	}
}

void	ft_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	handle_signal(void)
{
	if (signal(SIGUSR1, build_symbol) == SIG_ERR)
		ft_error("Failed to set action for SIGUSR1\n");
	if (signal(SIGUSR2, build_symbol) == SIG_ERR)
		ft_error("Failed to set action for SIGUSR2\n");
}
