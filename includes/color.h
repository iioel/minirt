/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:49:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/02 20:37:41 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_ambient	t_ambient;
typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

t_color	color_init(char r, char g, char b);
t_color	compute_ambiant(t_ambient *a, t_color c);
int		color2int(t_color c);

#endif
