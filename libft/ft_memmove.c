/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:30:13 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:30:21 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (! dst && ! src)
		return (NULL);
	if (dst <= src)
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)(dst) + i)
				= *((unsigned char *)(src) + i);
			i++;
		}
	}
	else
	{
		while (len > 0)
		{
			*((unsigned char *)(dst) + len - 1)
				= *((unsigned char *)(src) + len - 1);
			len--;
		}
	}
	return (dst);
}
