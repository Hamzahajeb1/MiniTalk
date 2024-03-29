/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:31:35 by hel-haji          #+#    #+#             */
/*   Updated: 2024/03/29 02:35:17 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	i;
	static int	j;
	int			n;

	if (sig == SIGUSR1)
		n = 0;
	else
		n = 1;
	j = (j << 1) + n;
	i++;
	if (i == 8)
	{
		write(1, &j, 1);
		i = 0;
		j = 0;
	}
}

int	main(void)
{
	signal (SIGUSR1, handler);
	signal (SIGUSR2, handler);
	write(1, "Hello, Here's the PID => ", 25);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
