/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 12:16:17 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/13 15:38:58 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_countdigits(int n)
{
	size_t			size;

	size = 0;
	if (n == 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	size_t			size;
	char			neg;
	char			*word;
	unsigned int	u_n;

	u_n = (unsigned int)(n);
	neg = (n < 0);
	if (neg)
		u_n = (unsigned int)(n * -1);
	size = ft_countdigits(u_n) + neg + 1;
	word = malloc((size) * sizeof(char));
	if (word == NULL)
		return (NULL);
	word[--size] = 0;
	if (neg)
		word[0] = '-';
	if (u_n == 0)
		word[0] = '0';
	while (u_n > 0)
	{
		word[--size] = u_n % 10 + '0';
		u_n /= 10;
	}
	return (word);
}
