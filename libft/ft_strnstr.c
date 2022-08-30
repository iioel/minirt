/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:20:23 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/18 21:39:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	tofind_size;

	i = 0;
	tofind_size = ft_strlen(tofind);
	if (ft_strlen(str) < tofind_size || tofind_size > len)
		return (NULL);
	while (i + tofind_size <= len)
	{
		if (tofind_size == 0 || ft_strncmp(str + i, tofind, tofind_size) == 0)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
