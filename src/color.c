/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:53:37 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 15:50:16 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

t_color	color_init(int r, int g, int b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color	color_cap(t_color c1)
{
	if (c1.r > 255)
		c1.r = 255;
	if (c1.g > 255)
		c1.g = 255;
	if (c1.b > 255)
		c1.b = 255;
	return (c1);
}

t_color	color_add(t_color c1, t_color c2)
{
	c1.r = c1.r + c2.r;
	c1.g = c1.g + c2.g;
	c1.b = c1.b + c2.b;
	c1 = color_cap(c1);
	return (c1);
}

t_color	color_max(t_color c1, t_color c2)
{
	if (c1.r < c2.r)
		c1.r = c2.r;
	if (c1.g < c2.g)
		c1.g = c2.g;
	if (c1.b < c2.b)
		c1.b = c2.b;
	return (c1);
}

int	color2int(t_color c)
{
	return ((c.r << 16) + (c.g << 8) + c.b);
}
