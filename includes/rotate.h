/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:23:19 by yoel              #+#    #+#             */
/*   Updated: 2022/10/17 11:24:16 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROTATE_H
# define ROTATE_H

# include "point.h"

t_point	rotate(t_point p, double ax, double ay, double az);
t_point	rev_rotate(t_point p, double ax, double ay, double az);

#endif
