/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:14:56 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/18 21:38:18 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dstinitlen;

	dstinitlen = ft_strlen(dst);
	i = dstinitlen;
	if (dstinitlen >= dstsize)
		return (dstsize + ft_strlen(src));
	while (i < (dstsize - 1) && *(src + i - dstinitlen))
	{
		*(dst + i) = *(src + i - dstinitlen);
		i++;
	}
	*(dst + i) = 0;
	return (dstinitlen + ft_strlen(src));
}
