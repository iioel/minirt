/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:15:13 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:15:27 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0)
	{
		if (*(s + i) == (char)(c))
			return ((char *)(s + i));
		i++;
	}
	if (*(s + i) == c)
		return ((char *)(s + i));
	return (NULL);
}
