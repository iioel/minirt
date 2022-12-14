/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:11:23 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 18:19:15 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	max(int m1, int m2)
{
	if (m1 < m2)
		return (m2);
	return (m1);
}

int	min(int m1, int m2)
{
	if (m1 > m2)
		return (m2);
	return (m1);
}
