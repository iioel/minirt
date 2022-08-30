/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:30:35 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:31:02 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	void	*out;

	i = 0;
	out = (void *)(s);
	while (i < n)
	{
		if (*((unsigned char *)(out) + i) == (unsigned char)(c))
			return (out + i);
		i++;
	}
	return (NULL);
}
