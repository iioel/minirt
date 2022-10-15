/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:15:11 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 17:18:54 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_img	*create_image(t_window *w)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (! img)
		return (NULL);
	img->width = w->width;
	img->height = w->height;
	img->img = mlx_new_image(w->mlx, img->width, img->height);
	if (! img->img)
	{
		free(img);
		return (NULL);
	}
	img->pixel_bits = 4 * 8;
	img->line_bytes = 4 * w->width;
	img->endian = 0;
	img->addr = mlx_get_data_addr(img->img, &img->pixel_bits,
			&img->line_bytes, &img->endian);
	return (img);
}

void	display_image(t_window *w, t_img *img)
{
	mlx_clear_window(w->mlx, w->w);
	mlx_put_image_to_window(w->mlx, w->w, img->img, 0, 0);
}

void	mlx_pixel_put_img(t_img *img, int x, int y, unsigned int color)
{
	char	*p_loc;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		p_loc = img->addr + (y * img->line_bytes + x * (img->pixel_bits / 8));
		*(unsigned int *)p_loc = color;
	}
}

unsigned int	mlx_get_c(t_img *img, int x, int y)
{
	char	*p_loc;

	if (x >= 0 && x < img->width && y >= 0 && y < img->height)
	{
		p_loc = img->addr + (y * img->line_bytes + x * (img->pixel_bits / 8));
		return (*(unsigned int *)p_loc);
	}
	return (-1);
}
