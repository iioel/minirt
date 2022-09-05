/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 16:23:45 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_type	get_type(char *str)
{
	if (!ft_strncmp("A", str, ft_strlen("A") + 1))
		return (ambient);
	else if (!ft_strncmp("C", str, ft_strlen("C") + 1))
		return (camera);
	else if (!ft_strncmp("L", str, ft_strlen("L") + 1))
		return (light);
	else if (!ft_strncmp("sp", str, ft_strlen("sp") + 1))
		return (sphere);
	else if (!ft_strncmp("pl", str, ft_strlen("pl") + 1))
		return (plane);
	else if (!ft_strncmp("cy", str, ft_strlen("cy") + 1))
		return (cylinder);
	else
		return (unknown);
}

void	*new_camera(char *str)
{
	t_camera	*c;
	char		*stype;

	c = ft_calloc(1, sizeof(t_camera));
	if (!c)
		return (NULL);
	c->point = ft_calloc(1, sizeof(t_point));
	if (!(c->point))
		return (NULL);
	c->vect = ft_calloc(1, sizeof(t_vector));
	if (!(c->vect))
		return (NULL);
	ft_sscanf(str, "%s %f,%f,%f %f,%f,%f %i", &stype, &(c->point->x),
		&(c->point->y), &(c->point->z), &(c->vect->x), &(c->vect->y),
		&(c->vect->z), &(c->fov));
	c->type = get_type(stype);
	free(stype);
	return (c);
}

void	*new_ambient(char *str)
{
	t_ambient	*a;
	char		*stype;

	a = ft_calloc(1, sizeof(t_ambient));
	if (!a)
		return (NULL);
	a->color = ft_calloc(1, sizeof(t_color));
	if (!(a->color))
		return (NULL);
	ft_sscanf(str, "%s %f #%2x%2x%2x", &stype, &(a->lighting), &(a->color->r),
		&(a->color->g), &(a->color->b));
	a->type = get_type(stype);
	free(stype);
	return (a);
}

void	*new_object(char *str)
{
	t_type	type;
	char	*stype;

	if (!ft_sscanf(str, "%s", &stype))
		return (NULL);
	type = get_type(stype);
	free(stype);
	if (type == ambient)
		return (new_ambient(str));
	else if (type == camera)
		return (new_camera(str));
	else if (type == light)
		return (new_light(str));
	else if (type == sphere)
		return (new_sphere(str));
	else if (type == plane)
		return (new_plane(str));
	else if (type == cylinder)
		return (new_cylinder(str));
	else
		return (NULL);
}

t_list	*parsing(char *file)
{
	int		fd;
	t_list	*lst;
	char	*str;
	void	*tmp;

	str = NULL;
	lst = ft_lstnew(NULL);
	fd = open(file, O_RDONLY);
	if (!fd)
		return (NULL);
	str = get_next_line(fd);
	while (str)
	{
		tmp = new_object(str);
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&lst, ft_lstnew(tmp));
		str = get_next_line(fd);
	}
	close(fd);
	tmp = lst->next;
	free(lst);
	lst = tmp;
	return (lst);
}
