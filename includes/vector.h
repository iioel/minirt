/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/05 13:49:43 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <math.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vector;

// vector_1.c
t_vector	*vec_init(const double x, const double y, const double z);
t_vector	*vec_dup(const t_vector vec);
t_vector	*vec_cpy(t_vector *vec, const t_vector vec2);
t_vector	*vec_sub(const t_vector vec, const t_vector vec2);
t_vector	*vec_add(const t_vector vec, const t_vector vec2);

// vector_2.c
t_vector	*vec_mul(const t_vector vec, const t_vector vec2);
t_vector	*vec_mul_nb(const t_vector vec, const double nb);
t_vector	*vec_div(const t_vector vec, const double nb);
double		vec_length_squared(const t_vector vec);
double		vec_length(const t_vector vec);

// vector_3.c
double		vec_dot(const t_vector vec, const t_vector vec2);
t_vector	*vec_cross(const t_vector vec, const t_vector vec2);
t_vector	*vec_unit(const t_vector vec);

#endif
