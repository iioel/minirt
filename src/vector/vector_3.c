/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:12:47 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 21:31:12 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double	vec_dot(const t_vector vec, const t_vector vec2)
{
	return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

t_vector	vec_cross(const t_vector vec, const t_vector vec2)
{
	return (vec_init(vec.y * vec2.z - vec.z * vec2.y,
			vec.z * vec2.x - vec.x * vec2.z,
			vec.x * vec2.y - vec.y * vec2.x));
}

t_vector	vec_unit(const t_vector vec)
{
	return (vec_div(vec, vec_length(vec)));
}
