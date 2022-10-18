/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:42:24 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 10:44:08 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "object.h"
# include "ray.h"

typedef struct s_light
{
	t_type			type;
	t_intercept		intercept;
	t_get_normal	get_normal;
	t_color			color;
	t_error			error;
	t_point			point;
	double			brightness;
}				t_light;

void	*new_light(char *str);
t_color	compute_lights(t_hit *hit, t_list *lst);

#endif
