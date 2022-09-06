/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:22:25 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/06 15:41:36 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	*ray_init(t_point origin, t_vector dir)
{
	t_ray	*ray;

	ray = ft_calloc(1, sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->dir = dir;
	return (ray);
}

t_point	ray_at(const t_ray ray, const double t)
{
	t_point	dest;

	dest = vec_add(ray.origin, vec_mul_nb(ray.dir, t));
	return (dest);
}
