/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/23 18:22:29 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "obj/camera.h"
#include "ray.h"
#include "parsing.h"
#include <unistd.h>

int	render_bis(t_window *w, t_img *img)
{
	int		x;
	int		y;
	t_ray	ray;
	t_color	color;

	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			if (x == 0 || (x / w->rd_i) != ((x - 1) / w->rd_i))
			{
				ray = pix2ray(w, x, y);
				ray_color(ray, &color, w->objs);
			}
			mlx_pixel_put_img(img, x++, y, color2int(color));
		}
		y++;
	}
	return (0);
}

int	render(t_window *w)
{
	t_img	*img;

	if (w->rd_i == 0)
	{
		usleep(2000);
		return (0);
	}
	img = create_image(w);
	render_bis(w, img);
	display_image(w, img);
	mlx_destroy_image(w->mlx, img->img);
	free(img);
	if (w->rd_i >= 1)
		w->rd_i--;
	return (0);
}

void	define_hooks(t_window *w)
{
	mlx_hook(w->w, 2, (1L << 0), catch_key, w);
	mlx_hook(w->w, 17, (1L << 0), catch_exit, w);
	mlx_hook(w->w, 4, (1L << 2), catch_button_press, w);
	mlx_hook(w->w, 5, (1L << 3), catch_button_release, w);
	mlx_hook(w->w, 6, (1L << 8), catch_mouse_moves, w);
	mlx_hook(w->w, 6, (1L << 6), catch_mouse_moves, w);
}

int	main(int argc, char **argv)
{
	t_window	*w;

	w = create_win(900, 16. / 9., "Minirt");
	if (! w)
		exit(1);
	w->rd_i = RENDER_STEPS;
	if (argc == 2)
		w->objs = parsing(argv[1]);
	else
		exit(print_error("Please provide a config file !!!\nExiting...\n"));
	error(w);
	w->camera = (t_camera *)get_obj(camera, w->objs);
	camera_init(w->camera, 16. / 9.);
	w->ambient = (t_ambient *)get_obj(ambient, w->objs);
	printf("Windows size x: %d y: %d \n", w->width, w->height);
	save_window(w);
	render(w);
	define_hooks(w);
	mlx_do_key_autorepeaton(w->mlx);
	mlx_loop_hook(w->mlx, render, w);
	mlx_loop(w->mlx);
}
