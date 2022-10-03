/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:16:26 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:54:07 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/ambient.h"

void	*new_ambient(char *str)
{
	t_ambient	*a;
	char		*stype;

	a = ft_calloc(1, sizeof(t_ambient));
	if (!a)
		return (NULL);
	ft_sscanf(str, "%s %f #%2x%2x%2x", &stype, &(a->lighting), &(a->color.r),
		&(a->color.g), &(a->color.b));
	a->type = get_type(stype);
	a->intercept = NULL;
	free(stype);
	return (a);
}

t_color	compute_ambiant(t_ambient *a, t_color c)
{
	t_color	out;

	out.r = (a->color.r * a->lighting) / 255. * c.r;
	out.g = (a->color.g * a->lighting) / 255. * c.g;
	out.b = (a->color.b * a->lighting) / 255. * c.b;
	return (out);
}
