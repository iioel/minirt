/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:39:15 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "point.h"
# include "color.h"
# include "ray.h"
//# include "minirt.h"

typedef struct s_object		t_object;

typedef double				(*t_intercept)	(t_object *, t_ray *, t_vector *);
typedef	int					(*t_error) 		(t_object *);
typedef t_vector			(*t_get_normal)	(t_object *, t_point);

typedef enum e_type
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cylinder,
	unknown
}			t_type;

struct s_object
{
	t_type			type;
	t_intercept		intercept;
	t_get_normal	get_normal;
	t_color			color;
	t_error			error;
};

t_type		get_type(char *str);
char		*get_strtype(t_type t);
void		*new_object(char *str);
t_object	*get_obj(t_type type, t_list *lst);

#endif
