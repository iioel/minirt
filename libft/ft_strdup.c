/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:23:37 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:24:03 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	s1_size;
	char	*out;

	i = 0;
	s1_size = ft_strlen(s1);
	out = ft_calloc((s1_size + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	while (i < s1_size)
	{
		*(out + i) = *(s1 + i);
		i++;
	}
	return (out);
}
