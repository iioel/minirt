/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 10:48:33 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/13 11:36:21 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u_n;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		u_n = (unsigned int)(n * -1);
	}
	else
		u_n = (unsigned int)(n);
	if (u_n >= 10)
	{
		ft_putnbr_fd(u_n / 10, fd);
		ft_putnbr_fd(u_n % 10, fd);
	}
	else
		ft_putchar_fd(u_n + '0', fd);
}
