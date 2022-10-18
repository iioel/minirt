/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:38 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 16:49:17 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "minirt.h"
#include "ray.h"
#include "hit.h"

void	fill_hit(t_hit *hit, t_ray *ray)
{
	hit->r = ray;
	hit->p = vec_add(hit->r->origin, vec_mul_nb(hit->r->dir, hit->d));
	hit->n = vec_unit(hit->n);
	if (vec_dot(hit->n, hit->r->dir) > 0)
		hit->n = vec_mul_nb(hit->n, -1);
}

int	get_nearest_obj(t_hit *hit, t_ray *ray, t_list *lst)
{
	double		res;
	t_vector	n;

	hit->d = DBL_MAX;
	hit->o = NULL;
	while (lst)
	{
		if (((t_object *)lst->content)->intercept)
		{
			res = ((t_object *)lst->content)->intercept((lst->content), ray,
					&n);
			if ((hit->o == NULL || res < hit->d) && res >= 0)
			{
				hit->d = res;
				hit->n = n;
				hit->o = (t_object *)lst->content;
			}
		}
		lst = lst->next;
	}
	if (hit->o != NULL)
		fill_hit(hit, ray);
	return (hit->o != NULL);
}
