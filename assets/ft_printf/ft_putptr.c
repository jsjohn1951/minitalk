/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:07:30 by wismith           #+#    #+#             */
/*   Updated: 2022/02/02 13:44:50 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(unsigned long int num)
{
	int	i;

	i = 0;
	while (num > 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

char	*ft_ptr_algo(char *res, unsigned long int num)
{
	int	i;
	int	rem;

	i = 0;
	rem = 0;
	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			res[i] = rem + 48;
		else
			res[i] = rem + 87;
		num /= 16;
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_putptr(unsigned long int num)
{
	int		len;
	char	*res;

	if (num == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	len = ft_ptrlen(num);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res = ft_ptr_algo(res, num);
	ft_strrev(res);
	ft_putstr("0x");
	ft_putstr(res);
	free (res);
	res = NULL;
	return (len + 2);
}
