/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:37:13 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 19:52:11 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (!s || !f)
		return (NULL);
	i = 0;
	out = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (out == NULL)
		return (NULL);
	while (*(s + i) != 0)
	{
		*(out + i) = f(i, *(s + i));
		i++;
	}
	return (out);
}
