/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 16:23:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*new_light(char *str)
{
	t_light	*l;
	char	*stype;

	l = ft_calloc(1, sizeof(t_light));
	if (!l)
		return (NULL);
	l->point = ft_calloc(1, sizeof(t_point));
	if (!(l->point))
		return (NULL);
	l->color = ft_calloc(1, sizeof(t_color));
	if (!(l->color))
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %i", &stype, &(l->point->x),
		&(l->point->y), &(l->point->z), &(l->brightness), &(l->color->r),
		&(l->color->g), &(l->color->b));
	l->type = get_type(stype);
	free(stype);
	return (l);
}

void	*new_sphere(char *str)
{
	t_sphere	*s;
	char		*stype;

	s = ft_calloc(1, sizeof(t_sphere));
	if (!s)
		return (NULL);
	s->point = ft_calloc(1, sizeof(t_point));
	if (!(s->point))
		return (NULL);
	s->color = ft_calloc(1, sizeof(t_color));
	if (!(s->color))
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %i", &stype, &(s->point->x),
		&(s->point->y), &(s->point->z), &(s->diameter), &(s->color->r),
		&(s->color->g), &(s->color->b));
	s->type = get_type(stype);
	free(stype);
	return (s);
}

void	*new_plane(char *str)
{
	t_plane	*p;
	char	*stype;

	p = ft_calloc(1, sizeof(t_plane));
	if (!p)
		return (NULL);
	p->point = ft_calloc(1, sizeof(t_point));
	if (!(p->point))
		return (NULL);
	p->color = ft_calloc(1, sizeof(t_color));
	if (!(p->color))
		return (NULL);
	p->vect = ft_calloc(1, sizeof(t_vector));
	if (!(p->vect))
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f #%2x%2x%2x", &stype, &(p->point->x),
		&(p->point->y), &(p->point->z), &(p->vect->x), &(p->vect->y),
		&(p->vect->z), &(p->color->r), &(p->color->g), &(p->color->b));
	p->type = get_type(stype);
	free(stype);
	return (p);
}

void	*new_cylinder(char *str)
{
	t_cylinder	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_plane));
	if (!c)
		return (NULL);
	c->point = ft_calloc(1, sizeof(t_point));
	if (!(c->point))
		return (NULL);
	c->color = ft_calloc(1, sizeof(t_color));
	if (!(c->color))
		return (NULL);
	c->vect = ft_calloc(1, sizeof(t_vector));
	if (!(c->vect))
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %f %f #%2x%2x%2x", &stype,
		&(c->point->x), &(c->point->y), &(c->point->z), &(c->vect->x),
		&(c->vect->y), &(c->vect->z), &(c->diameter), &(c->height),
		&(c->color->r), &(c->color->g), &(c->color->b));
	c->type = get_type(stype);
	free(stype);
	return (c);
}
