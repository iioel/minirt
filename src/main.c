/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/26 18:07:35 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "camera.h"
#include "ray.h"

static void	little_test(t_window *w)
{
	int		x;
	int		y;
	t_img	*img;

	img = create_image(w);
	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
			mlx_pixel_put_img(img, x++, y, 0x0000FFFF);
		y++;
	}
	display_image(w, img);
}

void	render(t_window *w)
{
	int		x;
	int		y;
	t_ray	ray;
	t_img	*img;
	t_color	color;

	img = create_image(w);
	y = 0;
	while (y < w->height)
	{
		x = 0;
		while (x < w->width)
		{
			ray = pix2ray(w, x, y);
			ray_color(ray, &color, w->objs);
			mlx_pixel_put_img(img, x++, y, color2int(color));
		}
		y++;
	}
	display_image(w, img);
}

static void	define_hooks(t_window *w)
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
	if (argc == 2)
		w->objs = parsing(argv[1]);
	else
	{
		printf("Please provide a config file !!!\nExiting...\n");
		exit(1);
	}
	w->camera = get_camera(w->objs);
	camera_init(w->camera, 16. / 9.);
	printf("Windows size x: %d y: %d \n", w->width, w->height);
	save_window(w);
	little_test(w);
	render(w);
	define_hooks(w);
	mlx_do_key_autorepeaton(w->mlx);
	mlx_loop(w->mlx);
}
