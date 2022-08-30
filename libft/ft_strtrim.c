/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 20:25:44 by ycornamu          #+#    #+#             */
/*   Updated: 2021/10/14 20:26:30 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	size_t			len;
	size_t			s1_len;

	if (! s1 || ! set)
		return (NULL);
	start = 0;
	len = 0;
	s1_len = ft_strlen(s1);
	while (ft_strchr(set, *(s1 + start)) != NULL)
		start++;
	while (ft_strchr(set, *(s1 + s1_len - 1 - len)) != NULL)
		len++;
	len = s1_len - start - len;
	return (ft_substr(s1, start, len));
}
