/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:23:46 by wismith           #+#    #+#             */
/*   Updated: 2022/03/21 15:17:30 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/server.h"

int	stat_set(int c)
{
	static char	*index;
	char		*truth;

	truth = "true";
	if (index != truth)
		c = 0;
	index = truth;
	return (c);
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	s;
	static int				c;

	(void) ucontext;
	(void) info;
	c = stat_set(c);
	if (sig == SIGUSR2)
		s = s << 1 | 1;
	else if (sig == SIGUSR1)
		s = s << 1;
	c++;
	if (c == 8)
	{
		write(1, &s, 1);
		c = 0;
		s = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					*p;

	p = &sa.sa_flags;
	sa.sa_sigaction = &handler;
	sigemptyset(p);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server %sStarted%s...\n", KGRN, KNRM);
	ft_printf("\nServer pID:\t%s%d%s\n", KMAG, getpid(), KNRM);
	while (1)
		pause();
	return (0);
}
