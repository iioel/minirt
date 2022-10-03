/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:42:24 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:43:41 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "object.h"
# include "ray.h"

typedef struct s_light
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	t_point		point;
	double		brightness;
}				t_light;

void	*new_light(char *str);
t_color	compute_lights(t_color c, t_object *o, t_ray ray, double d, t_list *lst);

#endif
