/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:19:38 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 22:10:20 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "minirt.h"
#include "ray.h"

double	get_nearest_obj(t_object **obj, t_ray ray, t_list *lst)
{
	double		res;
	double		nearest;
	t_object	*nearest_obj;

	nearest = DBL_MAX;
	nearest_obj = NULL;
	while (lst)
	{
		if (((t_object *)lst->content)->intercept)
		{
			res = ((t_object *)lst->content)->intercept((lst->content), &ray);
			if ((nearest_obj == NULL || res < nearest) && res >= 0)
			{
				nearest = res;
				nearest_obj = (t_object *)lst->content;
			}
		}
		lst = lst->next;
	}
	*obj = nearest_obj;
	return (nearest);
}
