/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:29:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 16:15:15 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "obj/object.h"

typedef struct s_cylinder
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	t_vector	vect;
	double		diameter;
	double		height;
}				t_cylinder;

void		*new_cylinder(char *str);

#endif
