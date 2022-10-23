/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:16:26 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 18:47:19 by yoel             ###   ########.fr       */
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
	a->error = &error_ambient;
	free(stype);
	return (a);
}

t_color	compute_ambiant(t_hit *hit, t_list *lst)
{
	t_ambient	*a;
	t_color		out;
	t_color		c;

	c = hit->o->color;
	a = (t_ambient *)get_obj(ambient, lst);
	if (a == NULL)
		return (color_init(0,0,0));
	out.r = (a->color.r * a->lighting) / 255. * c.r;
	out.g = (a->color.g * a->lighting) / 255. * c.g;
	out.b = (a->color.b * a->lighting) / 255. * c.b;
	return (out);
}
