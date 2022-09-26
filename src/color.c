/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:53:37 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/20 15:36:48 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"
#include "color.h"

t_color	color_init(char r, char g, char b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

int	color2int(t_color c)
{
	return ((c.r << 16) + (c.g << 8) + c.b);
}
