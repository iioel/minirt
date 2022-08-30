/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:24:32 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/18 20:57:55 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*out;

	if (! s)
		return (NULL);
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	else if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	out = malloc((len + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	if (start < ft_strlen(s))
	{
		while (i < start)
			i++;
		while (i < (len + start))
		{
			*(out + i - start) = *(s + i);
			i++;
		}
	}
	*(out + i - start) = 0;
	return (out);
}
