/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:40:47 by wismith           #+#    #+#             */
/*   Updated: 2022/03/22 17:42:16 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

void	err_msg(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(2, &s[i], 1);
}

void	pid_check(int pid)
{
	if (pid < 0)
	{
		err_msg("Error!\n");
		ft_printf("\t%s'pID'%s is %snegative%s\n", KMAG, KNRM, KRED, KNRM);
		ft_printf("\t%s'pID'%s must be %spositive%s\n\n", KMAG, KNRM, KGRN, KNRM);
		exit(1);
	}
}

void	err_giv_info(void)
{
	ft_printf("\t%sNon Numerical%s", KRED, KNRM);
	ft_printf(" characters found in %spID%s\n", KMAG, KNRM);
	ft_printf("\nFormat as follows:\n\n");
	ft_printf("\t$ %s./client%s  '%spID%s", KGRN, KNRM, KMAG, KNRM);
	ft_printf(" (%snumerical only%s)'", KRED, KNRM);
	ft_printf("  '%smessage%s'\n\n", KYEL, KNRM);
}

void	char_check(char *s)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	if (s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			check = -1;
		i++;
	}
	if (check == -1)
	{
		err_msg("Error!\n");
		err_giv_info();
		exit(1);
	}
}

void	arg_check(int argc, char *s)
{
	int	i;

	i = 0;
	if (argc < 3)
	{
		err_msg("Error!\n");
		ft_printf("\t%sToo few arguments%s present!\n", KRED, KNRM);
		ft_printf("\tRequires '%s2%s' arguments to proceed\n\n", KGRN, KNRM);
		i = -1;
	}
	if (argc > 3)
	{
		err_msg("Error!\n");
		ft_printf("\t%sToo many arguments%s present!\n", KRED, KNRM);
		ft_printf("\tRequires '%s2%s' arguments to proceed\n\n", KGRN, KNRM);
		i = -1;
	}
	if (argc >= 3)
		char_check(s);
	if (i == -1)
		exit(1);
}
