/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avelikan <avelikan@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 14:57:47 by avelikan          #+#    #+#             */
/*   Updated: 2024/08/13 14:57:50 by avelikan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

pid_t	server_pid;

static void print_error_1(void)
{
	write(2, "Error: Failed to send signal to process\n", 40);
	exit(1);
}

static void print_error_2(void)
{
	write(2, "The input should have 2 arguments: PID and string\n", 50);
	exit(1);
}

void send_binary(char *s)
{
	int		i;
	int		count;
	int		err_check_1;
	char	c;

	i = 0;
	while(s[i])
	{
		count = 7;
		while (count >= 0)
		{
			c = (s[i] >> count) & 1;
			if (c == 1)
				err_check_1 = kill(server_pid, SIGUSR1);
			else
				err_check_1 = kill(server_pid, SIGUSR2);
			if (err_check_1 == -1)
				print_error_1();
			count--;
			usleep(500);
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac == 3)
	{
		
	}
}