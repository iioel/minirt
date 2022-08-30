/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 11:50:19 by ycornamu          #+#    #+#             */
/*   Updated: 2021/11/16 10:40:38 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strcntword(char const *s, char sep)
{
	size_t	i;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (*(s + i))
	{
		while (*(s + i) == sep && *(s + i))
			i++;
		if (*(s + i))
		{
			while (*(s + i) != sep && *(s + i))
				i++;
			nb_words++;
		}
	}
	return (nb_words);
}

static size_t	ft_strdlen(char const *s, char d)
{
	size_t	i;

	i = 0;
	while (*(s + i) != 0 && *(s + i) != d)
		i++;
	return (i);
}

static int	ft_skipchar(char const *s, int index, char c)
{
	while (*(s + index) == c && *(s + index) != 0)
		index++;
	return (index);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;
	char	*word;

	if (!s)
		return (NULL);
	k = 0;
	j = ft_strcntword(s, c);
	tab = malloc((j + 1) * sizeof(char *));
	if (tab == NULL)
		return (NULL);
	*(tab + j--) = NULL;
	while (j >= 0)
	{
		k = ft_skipchar(s, k, c);
		i = ft_strdlen((s + k), c);
		word = ft_substr(s, k, i);
		if (word == NULL)
			return (NULL);
		*(tab + ft_strcntword(s, c) - j-- - 1) = word;
		k += i;
	}
	return (tab);
}
