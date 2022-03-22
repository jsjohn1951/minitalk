/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:29:36 by wismith           #+#    #+#             */
/*   Updated: 2022/03/22 17:42:54 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	ft_strlen_mod(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	err_msg_non_in_string(char *s)
{
	if (!ft_strlen_mod(s))
	{
		err_msg("Error!");
		ft_printf("\n\t%sNothing within string%s\n\n", KRED, KNRM);
		exit (1);
	}
}

void	bit_covrt(char c, int pid)
{
	int	shift;

	shift = 7;
	while (shift >= 0)
	{
		if (c >> shift & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		shift--;
		usleep(100);
	}
}

void	send_msg(char *s, int pid)
{
	int	i;

	i = 0;
	while (s[i])
	{
		bit_covrt(s[i], pid);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	arg_check(argc, argv[1]);
	pid = ft_atoi(argv[1]);
	pid_check(pid);
	err_msg_non_in_string(argv[2]);
	ft_printf("\nClient\n\t%sSending Msg%s ...\n\n", KGRN, KNRM);
	send_msg(argv[2], pid);
	return (0);
}
