/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:21:57 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 16:51:49 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "obj/object.h"
# include "color.h"
# include "hit.h"

typedef struct s_ambient
{
	t_type			type;
	t_intercept		intercept;
	t_color			color;
	t_error			error;
	double			lighting;
}				t_ambient;

void	*new_ambient(char *str);
t_color	compute_ambiant(t_hit *hit, t_list *lst);
int		error_ambient(t_object *o);

#endif
