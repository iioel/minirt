/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:17:35 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/13 03:41:05 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj/cylinder.h"
#include "ft_math.h"

void	*new_cylinder(char *str)
{
	t_cylinder	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_cylinder));
	if (!c)
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %f %f #%2x%2x%2x", &stype,
		&(c->point.x), &(c->point.y), &(c->point.z), &(c->vect.x),
		&(c->vect.y), &(c->vect.z), &(c->diameter), &(c->height),
		&(c->color.r), &(c->color.g), &(c->color.b));
	c->type = get_type(stype);
	c->intercept = &cylinder_inter;
	c->get_normal = &cylinder_get_normal;
	free(stype);
	return (c);
}

double	cylinder_inter(t_object *o, t_ray *r)
{
	t_ray		rb;
	t_vector	oc;
	t_cylinder	*c;
	double		eq[4];
	double		t1;
	double		t2;

	t1 = -1;
	c = (t_cylinder *)o;
	rb.origin = r->origin;
	rb.dir = vec_cross(r->dir, c->vect);
	oc = vec_sub(r->origin, c->point);
	eq[A] = vec_dot(rb.dir, rb.dir);
	eq[B] = 2. * vec_dot(rb.dir, vec_cross(oc, c->vect));
	eq[C] = vec_dot(vec_cross(oc, c->vect), vec_cross(oc, c->vect)) - (c->diameter / 2) * (c->diameter / 2);
	eq[DESC] = (eq[B] * eq[B]) - 4 * eq[A] * eq[C];
	if (eq[DESC] == 0)
		t1 = -(eq[B] / (2 * eq[A]));
	else if (eq[DESC] > 0)
	{
		t1 = (-eq[B] + sqrt(eq[DESC])) / (2 * eq[A]);
		t2 = (-eq[B] - sqrt(eq[DESC])) / (2 * eq[A]);
		if (t2 >= 0 && t2 < t1)
			t1 = t2;
	}

	double	max;

	max = sqrt((c->height / 2) * (c->height / 2) + (c->diameter / 2) * (c->diameter / 2));
	t_point		p = vec_add(r->origin, vec_mul_nb(r->dir, t1));
	t_vector	len = vec_sub(p, c->point);
	if (vec_length(len) > max)
		return (-1);
	return (t1);
}

t_point	rotate(t_point p, double ax, double ay, double az);
t_point	rev_rotate(t_point p, double ax, double ay, double az);

t_vector	cylinder_get_normal(t_object *o, t_point p)
{
	t_cylinder	*c;
	t_point		pbis;
	t_point		cpoint;
	double		ax;
	double		ay;
	t_vector	v;

	c = (t_cylinder *)o;
	c->vect = vec_unit(c->vect);
	ax = atan(c->vect.z / c->vect.x) * 180 / M_PI;
	if (c->vect.x < 0)
		ax += 180;
	ay = acos(c->vect.y / 1) * 180 / M_PI;
	if (c->vect.y == 1. || c->vect.y == -1)
	{
		ax = 0.;
		ay = 0.;
	}
	v = vec_dup(c->vect);
	printf("AX: %f AY: %f\n", ax, ay);
	printf("V: %f %f %f\n", v.x, v.y, v.z);
	v = rotate(v, 0, ax, ay);
	printf("VA: %f %f %f\n", v.x, v.y, v.z);
	v = rev_rotate(v, 0, -ax, ay);
	printf("VB: %f %f %f\n", v.x, v.y, v.z);
	pbis = vec_sub(p, c->point);
	pbis = rotate(pbis, 0, ax, ay);
	pbis = vec_add(pbis, c->point);
	cpoint = vec_dup(c->point);
	cpoint.y = pbis.y;
	cpoint = vec_sub(cpoint, c->point);
	cpoint = rev_rotate(cpoint, 0, -ax, -ay);
	cpoint = vec_add(cpoint, c->point);
	return (vec_unit(vec_sub(p, cpoint)));
}

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
