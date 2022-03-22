/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 10:55:30 by wismith           #+#    #+#             */
/*   Updated: 2022/03/21 15:19:34 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/client.h"

int	min_err(void)
{
	err_msg("Error!");
	ft_printf("\n\tpid: %sMin int Reached!%s\n\n", KRED, KNRM);
	return (-1);
}

void	max_err(void)
{
	err_msg("Error!");
	ft_printf("\n\tpID: %sMax int Reached!%s\n\n", KRED, KNRM);
	exit(1);
}

int	ft_atoi(const char *nptr)
{
	size_t	res;
	int		i;
	int		ncounter;

	res = 0;
	i = 0;
	ncounter = 0;
	while ((nptr[i] >= 7 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			ncounter++;
	while (nptr[i] && (nptr[i] >= 48 && nptr[i] <= 57))
	{
		res *= 10;
		res += nptr[i++] - '0';
		if (res >= 2147483647 && ncounter == 0)
			max_err();
		if (res >= 2147483647 && ncounter > 0)
			return (min_err());
	}
	if (ncounter > 0)
		res *= -1;
	return (res);
}
