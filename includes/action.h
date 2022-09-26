/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:09:16 by yoel              #+#    #+#             */
/*   Updated: 2022/09/26 19:18:49 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTION_H
# define ACTION_H

# include "minirt.h"
# include "vector.h"
# include "camera.h"

# define FW 0
# define BACK 1
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3

void	move(t_window *w, int dir);
void	look(t_window *w, int dir);
#endif
