/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:50:36 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/13 18:35:14 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_minitalk.h"

void	ft_send_bit(unsigned int val, pid_t pid_server, int bit)
{
	while (bit != 0)
	{
		if (val % 2 == 0)
			kill (pid_server, SIGUSR1);
		if (val % 2 == 1)
			kill (pid_server, SIGUSR2);
		val /= 2;
		bit--;
		usleep(100);
	}
}

void	ft_error(void)
{
	write (1, "Error\n", 6);
	exit (1);
}

void	ft_correct_msg(int sigusr)
{
	(void)sigusr;
	write (1, "Messaggio ricevuto con successo\n", 33);
	exit(0);
}

int	main(int argc, char *argv[])
{
	unsigned int	pid_server;
	int				i;

	(void) argc;
	i = 0;
	if (argc != 3)
		ft_error();
	signal (SIGUSR1, ft_correct_msg);
	pid_server = ft_atoi(argv[1]);
	ft_send_bit(getpid(), pid_server, 32);
	while (argv[2] != NULL && argv[2][i] != 0)
		ft_send_bit(argv[2][i++], pid_server, 8);
	ft_send_bit(0, pid_server, 16);
	pause();
	return (0);
}
