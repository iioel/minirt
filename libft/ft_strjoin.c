/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:24:56 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:25:15 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1_size;
	size_t	s2_size;
	char	*out;

	if (! s1 || ! s2)
		return (NULL);
	i = -1;
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	out = malloc((s1_size + s2_size + 1) * sizeof(char));
	if (out == NULL)
		return (NULL);
	while (++i < s1_size)
		*(out + i) = *(s1 + i);
	while (i < (s1_size + s2_size))
	{
		*(out + i) = *(s2 + i - s1_size);
		i++;
	}
	*(out + i) = 0;
	return (out);
}
