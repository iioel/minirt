/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:29:37 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/18 19:50:07 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (! dst && ! src)
		return (NULL);
	while (i < n)
	{
		*((unsigned char *)(dst) + i) = *((unsigned char *)(src) + i);
		i++;
	}
	return (dst);
}
