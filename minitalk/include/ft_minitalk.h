/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 19:42:21 by graiolo           #+#    #+#             */
/*   Updated: 2023/01/13 17:05:24 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINITALK_H
# define FT_MINITALK_H

# include "../libft/include/ft_printf.h"

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdbool.h>

typedef struct s_signal
{
	unsigned char	val;
	int				i;
	bool			flag;
	int				pid_client;
}	t_signal;

#endif
