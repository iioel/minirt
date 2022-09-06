/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:19:22 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/06 15:39:55 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "point.h"
# include "vector.h"

typedef struct s_ray
{
	t_point		origin;
	t_vector	dir;
}			t_ray;

t_ray	*new_ray(t_point orign, t_vector dir);
t_point	ray_at(const t_ray ray, const double t);

#endif
