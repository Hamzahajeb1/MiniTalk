/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:31:47 by hel-haji          #+#    #+#             */
/*   Updated: 2024/03/29 02:29:09 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_send(int pid, char c)
{
	int	j;
	int	i;
	int	s[8];

	j = c;
	i = 7;
	while (i >= 0)
	{
		if (j == 0 || (j & 1) == 0)
			s[i] = 0;
		else if ((j & 1) == 1)
			s[i] = 1;
		if (j > 0)
			j = j >> 1;
		i--;
	}
	while (++i < 8)
	{
		if (s[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid == -1)
		{
			write(1, "forbidden PID!\n", 13);
			return (1);
		}
		while (argv[2] && *argv[2])
			sig_send(pid, *argv[2]++);
		sig_send(pid, '\n');
		return (0);
	}
	else
	{
		write(1, "the arguments are incorrect", 10);
		exit (1);
	}
}
