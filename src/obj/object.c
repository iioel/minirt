/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/03 17:35:11 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "obj/object.h"

char	*get_strtype(t_type type)
{
	if (type == ambient)
		return (ft_strdup("ambient"));
	else if (type == camera)
		return (ft_strdup("camera"));
	else if (type == light)
		return (ft_strdup("light"));
	else if (type == sphere)
		return (ft_strdup("sphere"));
	else if (type == plane)
		return (ft_strdup("plane"));
	else if (type == cylinder)
		return (ft_strdup("cylinder"));
	else
		return (ft_strdup("unknown"));
}

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

t_object	*get_obj(t_type type, t_list *lst)
{
	while (lst)
	{
		if (((t_object *)lst->content)->type == type)
			return (lst->content);
		lst = lst->next;
	}
	return (NULL);
}
