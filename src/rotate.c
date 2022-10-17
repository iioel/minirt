/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:20:58 by yoel              #+#    #+#             */
/*   Updated: 2022/10/17 11:21:34 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rotate.h"

void	mtx_mul(double a[3][3], double b[3][1])
{
	int		i;
	int		j;
	int		k;
	double	res[3][1];

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 1)
		{
			k = 0;
			res[i][j] = 0;
			while (k < 3)
			{
				res[i][j] += a[i][k] * b[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	b[0][0] = res[0][0];
	b[1][0] = res[1][0];
	b[2][0] = res[2][0];
}

void	mtx_setline(double (*line)[], double a, double b, double c)
{
	(*line)[0] = a;
	(*line)[1] = b;
	(*line)[2] = c;
}

void	get_angle_mtx(double (*m)[3][3][3], double ax, double ay, double az)
{
	double	a;
	double	b;
	double	c;

	a = ax * M_PI / 180;
	b = ay * M_PI / 180;
	c = az * M_PI / 180;
	mtx_setline(&(*m)[0][0], 1, 0, 0);
	mtx_setline(&(*m)[0][1], 0, cos(a), -sin(a));
	mtx_setline(&(*m)[0][2], 0, sin(a), cos(a));
	mtx_setline(&(*m)[1][0], cos(b), 0, sin(b));
	mtx_setline(&(*m)[1][1], 0, 1, 0);
	mtx_setline(&(*m)[1][2], -sin(b), 0, cos(b));
	mtx_setline(&(*m)[2][0], cos(c), -sin(c), 0);
	mtx_setline(&(*m)[2][1], sin(c), cos(c), 0);
	mtx_setline(&(*m)[2][2], 0, 0, 1);
}

t_point	rotate(t_point p, double ax, double ay, double az)
{
	double	point[3][1];
	double	m[3][3][3];

	point[0][0] = p.x;
	point[1][0] = p.y;
	point[2][0] = p.z;
	get_angle_mtx(&m, ax, ay, az);
	mtx_mul(m[0], point);
	mtx_mul(m[1], point);
	mtx_mul(m[2], point);
	p.x = point[0][0];
	p.y = point[1][0];
	p.z = point[2][0];
	return (p);
}

t_point	rev_rotate(t_point p, double ax, double ay, double az)
{
	double	point[3][1];
	double	m[3][3][3];

	point[0][0] = p.x;
	point[1][0] = p.y;
	point[2][0] = p.z;
	get_angle_mtx(&m, ax, ay, az);
	mtx_mul(m[2], point);
	mtx_mul(m[1], point);
	mtx_mul(m[0], point);
	p.x = point[0][0];
	p.y = point[1][0];
	p.z = point[2][0];
	return (p);
}
