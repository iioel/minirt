/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:19:51 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:20:06 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(s1 + i) != 0 && *(s2 + i) != 0)
	{
		if ((unsigned char)*(s1 + i) < (unsigned char)*(s2 + i))
			return (-1);
		else if ((unsigned char)*(s1 + i) > (unsigned char)*(s2 + i))
			return (1);
		i++;
	}
	if (i < n && (unsigned char)*(s1 + i) < (unsigned char)*(s2 + i))
		return (-1);
	else if (i < n && (unsigned char)*(s1 + i) > (unsigned char)*(s2 + i))
		return (1);
	else
		return (0);
}
