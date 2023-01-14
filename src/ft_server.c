/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:39:07 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/14 21:48:10 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minitalk.h"

void	ft_bit_char(bool bin)
{
	static t_signal	sign;

	sign.val += bin << sign.i;
	if (sign.flag == false)
		sign.pid_client += bin << sign.i;
	sign.i++;
	if (sign.flag == false && sign.i == 32)
	{
		sign.flag = true;
		sign.val = 0;
		sign.i = 0;
	}
	if (sign.flag == true && sign.i == 8)
	{
		write(1, &(sign.val), 1);
		if (sign.val == 0)
		{
			sign.flag = false;
			kill(sign.pid_client, SIGUSR1);
			sign.pid_client = 0;
		}
		sign.val = 0;
		sign.i = 0;
	}	
}

void	ft_sigusr(int sigusr)
{
	if (sigusr == SIGUSR1)
		ft_bit_char(0);
	if (sigusr == SIGUSR2)
		ft_bit_char(1);
}

int	main(void)
{
	struct sigaction	sign;

	sign.sa_handler = ft_sigusr;
	ft_printf("%d\n", getpid());
	while (true)
	{
		sigaction(SIGUSR1, &sign, NULL);
		sigaction(SIGUSR2, &sign, NULL);
	}
	return (0);
}
