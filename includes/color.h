/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 14:49:01 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/20 15:37:03 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}				t_color;

t_color	color_init(char r, char g, char b);
int		color2int(t_color c);

#endif
