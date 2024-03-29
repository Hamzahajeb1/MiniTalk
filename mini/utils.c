/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-haji <hel-haji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:31:13 by hel-haji          #+#    #+#             */
/*   Updated: 2024/03/29 02:39:52 by hel-haji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(long nb)
{
	char	i;

	if (nb / 10 > 0)
		ft_putnbr(nb / 10);
	i = nb % 10 + '0';
	write(1, &i, 1);
}

static	int	space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long long	n;
	int					sign;

	i = 0;
	n = 0;
	sign = 1;
	while (space(str[i]) == 1)
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		n = (n * 10) + str[i++] - 48;
		if (n >= LLONG_MAX && sign == 1)
			return (-1);
		else if (n >= LLONG_MAX && sign == -1)
			return (0);
	}
	return ((int)(n * sign));
}
