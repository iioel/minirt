/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:53:37 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 23:31:17 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "stdio.h"

t_color	color_init(char r, char g, char b)
{
	t_color	c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

t_color	color_add(t_color c1, t_color c2)
{
	c1.r = c1.r + c2.r;
	c1.g = c1.g + c2.g;
	c1.b = c1.b + c2.b;
	if (c1.r > 255)
		c1.r = 255;
	if (c1.g > 255)
		c1.g = 255;
	if (c1.b > 255)
		c1.b = 255;
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

void	int2color(int n, t_color *c)
{
	if (n == -1)
		c->r = -1;
	c->r = (n & 0xff0000) >> 16;
	c->g = (n & 0x00ff00) >> 8;
	c->b = (n & 0x0000ff);
}

void	color_moy(t_color *result, t_color *c1, t_color *c2, int mult)
{
	//printf("%i\n", mult);
	result->r = ((c1->r * mult) + c2->r) / (mult + 1);
	result->g = ((c1->g * mult) + c2->g) / (mult + 1);
	result->b = ((c1->b * mult) + c2->b) / (mult + 1);
}