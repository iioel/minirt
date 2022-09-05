/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:44:00 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 17:27:29 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	t_list		*lst;

	lst = NULL;
	if (argc == 2)
		lst = parsing(argv[1]);
	w = create_win(500, 500, "Minirt");
	if (! w)
		exit(1);
	printf("Windows size x: %d y: %d \n", w->width, w->height);
	save_window(w);
	little_test(w);
	define_hooks(w);
	mlx_do_key_autorepeaton(w->mlx);
	mlx_loop(w->mlx);
}
