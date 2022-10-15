/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:49:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 00:22:20 by yoel             ###   ########.fr       */
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

t_color	color_init(char r, char g, char b);
t_color	color_add(t_color c1, t_color c2);
t_color	color_max(t_color c1, t_color c2);
int		color2int(t_color c);
void	int2color(int n, t_color *c);
void	color_moy(t_color *result, t_color *c1, t_color *c2, int mult);

#endif
