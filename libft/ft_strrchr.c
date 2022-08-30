/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:15:49 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:15:52 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = ft_strlen(s);
	while ((slen + 1 - i) != 0)
	{
		if (*(s + slen - i) == (char)(c))
			return ((char *)(s + slen - i));
		i++;
	}
	return (NULL);
}
