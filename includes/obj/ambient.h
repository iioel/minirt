/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:21:57 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 15:41:24 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "obj/object.h"
# include "color.h"

typedef struct s_ambient
{
	t_type		type;
	t_intercept	intercept;
	t_color		color;
	double		lighting;
}				t_ambient;

void	*new_ambient(char *str);
t_color	compute_ambiant(t_ambient *a, t_color c);

#endif
