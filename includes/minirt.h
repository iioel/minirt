/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 11:55:05 by ycornamu          #+#    #+#             */
/*   Updated: 2022/10/04 04:52:06 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# include "keys.h"
# include "mouse.h"
# include "objects.h"

# define RENDER_STEPS 15

typedef enum e_type			t_type;
typedef struct s_object		t_object;
typedef struct s_color		t_color;

typedef struct s_window
{
	void		*mlx;
	void		*w;
	int			rd_i;
	double		aspect_ratio;
	int			width;
	int			height;
	t_list		*objs;
	t_camera	*camera;
	t_ambient	*ambient;
}				t_window;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
}				t_img;

// main.c
int			render(t_window *w);

// clean.c
void		*clean(void *p);

// window.c
t_window	*save_window(t_window *w);
t_window	*create_win(int width, double a_r, char *name);
int			clean_win(t_window *w);

// catch_win.c
int			catch_exit(int t, t_window *w);

// catch_key.c
int			catch_key(int t, t_window *w);

// catch_mouse.c
int			catch_button_press(int t, t_window *w);
int			catch_button_release(int t, t_window *w);
int			catch_mouse_moves(int x, int y, t_window *w);

// mlx_utils.c
t_img		*create_image(t_window *w);
void		display_image(t_window *w, t_img *img);
void		mlx_pixel_put_img(t_img *img, int x, int y, unsigned int color);

// gnl.c
char		*get_next_line(int fd);

#endif
