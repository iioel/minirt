/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 16:13:42 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# include "point.h"
# include "color.h"
# include "ray.h"
//# include "minirt.h"

# define A 0
# define B 1
# define C 2
# define DESC 3

typedef struct s_object		t_object;

typedef double				(*t_intercept)	(t_object *, t_ray *);

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
	t_type		type;
	t_intercept	intercept;
	t_color		color;
};

t_type		get_type(char *str);
void		*new_object(char *str);
t_object	*get_obj(t_type type, t_list *lst);

#endif
