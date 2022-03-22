/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wismith <wismith@42ABUDHABI.AE>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:18:23 by wismith           #+#    #+#             */
/*   Updated: 2022/03/22 18:06:42 by wismith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef CLIENT_H
# define CLIENT_H
# include <unistd.h>
# include <signal.h>
# include "../assets/ft_printf/ft_printf.h"

# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

void	arg_check(int argc, char *s);
void	err_msg(char *s);
int		ft_atoi(const char *nptr);
void	pid_check(int pid);

#endif
