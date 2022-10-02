/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 22:42:24 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/02 22:45:30 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

#ifndef LIGHT_H
# define LIGHT_H

t_color	compute_lights(t_color c, t_object *o, t_ray ray, double d, t_list *lst);

#endif
