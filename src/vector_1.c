/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:12:17 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/05 13:50:44 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vector	*vec_init(const double x, const double y, const double z)
{
	t_vector	*vec;

	vec = ft_calloc(1, sizeof(t_vector));
	if (! vec)
		return (NULL);
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

t_vector	*vec_dup(const t_vector vec)
{
	t_vector	*vec2;

	vec2 = vec_init(vec.x, vec.y, vec.z);
	return (vec2);
}

t_vector	*vec_cpy(t_vector *vec, const t_vector vec2)
{
	if (vec)
	{
		vec->x = vec2.x;
		vec->y = vec2.y;
		vec->z = vec2.z;
		return (vec);
	}
	return (NULL);
}

t_vector	*vec_sub(const t_vector vec, const t_vector vec2)
{
	t_vector	*vec_out;

	vec_out = ft_calloc(1, sizeof(t_vector));
	if (! vec_out)
		return (NULL);
	vec_out->x = vec.x - vec2.x;
	vec_out->y = vec.y - vec2.y;
	vec_out->z = vec.z - vec2.z;
	return (vec_out);
}

t_vector	*vec_add(const t_vector vec, const t_vector vec2)
{
	t_vector	*vec_out;

	vec_out = ft_calloc(1, sizeof(t_vector));
	if (! vec_out)
		return (NULL);
	vec_out->x = vec.x + vec2.x;
	vec_out->y = vec.y + vec2.y;
	vec_out->z = vec.z + vec2.z;
	return (vec_out);
}
