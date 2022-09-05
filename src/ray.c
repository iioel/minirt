/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:22:25 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:19 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*ray_init(t_point *orig, t_vector *dir)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->orig = orig;
	ray->dir = dir;
	return (ray);
}

t_point	*ray_at(const t_ray ray, const double t)
{
	t_point	*dest;
	t_point	*tmp;

	tmp = vec_mul_nb(*ray.dir, t);
	dest = vec_add(*ray.orig, *tmp);
	free(tmp);
	return (dest);
}
