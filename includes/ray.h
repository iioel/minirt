/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:19:22 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/20 15:32:57 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"
# include "point.h"
# include "vector.h"
# include "color.h"

typedef struct s_window t_window;

typedef struct s_ray
{
	t_point		origin;
	t_vector	dir;
}			t_ray;

t_ray	ray_init(t_point orign, t_vector dir);
t_point	ray_at(const t_ray ray, const double t);
t_ray	pix2ray(t_window *w, int x, int y);
int		ray_color(t_ray ray, t_color *color, t_list *objs);

#endif
