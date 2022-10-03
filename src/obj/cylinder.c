/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:17:35 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:55:29 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"

void	*new_cylinder(char *str)
{
	t_cylinder	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_cylinder));
	if (!c)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %f %f #%2x%2x%2x", &stype,
		&(c->point.x), &(c->point.y), &(c->point.z), &(c->vect.x),
		&(c->vect.y), &(c->vect.z), &(c->diameter), &(c->height),
		&(c->color.r), &(c->color.g), &(c->color.b));
	c->type = get_type(stype);
	c->intercept = NULL;
	free(stype);
	return (c);
}
