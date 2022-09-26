/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:12:06 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/26 18:20:03 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

t_camera	*get_camera(t_list *lst);
void		camera_init(t_camera *c, double a_r);
void		camera_upd_view(t_camera *c);

#endif
