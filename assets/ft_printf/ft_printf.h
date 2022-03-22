/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:49:31 by wismith           #+#    #+#             */
/*   Updated: 2022/02/10 12:32:20 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

//ft_printf.c
int		ft_printf(const char *s, ...);

//ft_put.c
int		ft_putchr(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);

//ft_put_u.c
int		ft_putnbr_u(unsigned int n);
int		ft_strlen(char *s);

//ft_put_hex.c
int		ft_puthex(unsigned int num, char c);
void	ft_strrev(char *src);

//ft_putptr.c
int		ft_putptr(unsigned long int num);

//ft_int_min.c
int		ft_min(void);
#endif