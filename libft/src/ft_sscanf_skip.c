/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_skip.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/05 17:38:29 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_int(char **str, int n)
{
	int	i;

	i = -1;
	if (!n)
		n = 2147483647;
	while ((*str)[++i] && i < n)
	{
		if (!ft_isdigit((*str)[i]))
			break ;
	}
	*str += i;
}

void	skip_hex(char **str, int n)
{
	int	i;

	i = -1;
	if (!n)
		n = 2147483647;
	while ((*str)[++i] && i < n)
	{
		if ((!ft_isdigit((*str)[i])) && !((*str)[i] <= 'f' && (*str)[i] >= 'a'))
			break ;
	}
	*str += i;
}

void	skip_float(char **str)
{
	int	i;

	i = -1;
	while (ft_isdigit((*str)[++i]))
		;
	if ((*str)[i] == '.')
		i++;
	while (ft_isdigit((*str)[++i]))
		;
	if ((*str)[i] == 'e' || (*str)[i] == 'E')
		i++;
	while (ft_isdigit((*str)[++i]))
		;
	*str += i;
}
