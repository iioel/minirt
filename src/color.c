/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:53:37 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/02 20:37:32 by ycornamu         ###   ########.fr       */
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

t_color	compute_ambiant(t_ambient *a, t_color c)
{
	t_color	out;

	out.r = (a->color.r * a->lighting) / 255. * c.r;
	out.g = (a->color.g * a->lighting) / 255. * c.g;
	out.b = (a->color.b * a->lighting) / 255. * c.b;
	return (out);
}

int	color2int(t_color c)
{
	return ((c.r << 16) + (c.g << 8) + c.b);
}
