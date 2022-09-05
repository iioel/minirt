/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:12:29 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/05 13:51:02 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vec_mul(const t_vector vec, const t_vector vec2)
{
	t_vector	*vec_out;

	vec_out = ft_calloc(1, sizeof(t_vector));
	if (! vec_out)
		return (NULL);
	vec_out->x = vec.x * vec2.x;
	vec_out->y = vec.y * vec2.y;
	vec_out->z = vec.z * vec2.z;
	return (vec_out);
}

t_vector	*vec_mul_nb(const t_vector vec, const double nb)
{
	t_vector	*vec_out;

	vec_out = ft_calloc(1, sizeof(t_vector));
	if (! vec_out)
		return (NULL);
	vec_out->x = vec.x * nb;
	vec_out->y = vec.y * nb;
	vec_out->z = vec.z * nb;
	return (vec_out);
}

t_vector	*vec_div(const t_vector vec, const double nb)
{
	t_vector	*vec_out;

	vec_out = vec_mul_nb(vec, 1. / nb);
	return (vec_out);
}

double	vec_length_squared(const t_vector vec)
{
	return (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
}

double	vec_length(const t_vector vec)
{
	return (sqrt(vec_length_squared(vec)));
}
