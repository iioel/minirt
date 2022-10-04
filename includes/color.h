/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:49:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 15:50:38 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

t_color	color_init(int r, int g, int b);
t_color	color_cap(t_color c1);
t_color	color_add(t_color c1, t_color c2);
t_color	color_max(t_color c1, t_color c2);
int		color2int(t_color c);

#endif
