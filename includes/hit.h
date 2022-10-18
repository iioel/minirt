/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:20:10 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/18 10:46:58 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HIT_H
# define HIT_H

typedef struct s_hit
{
	t_object	*o;
	double		d;
	t_point		p;
	t_vector	n;
	t_ray		*r;
}			t_hit;

#endif
