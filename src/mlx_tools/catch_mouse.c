/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_mouse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:55:21 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 17:20:31 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	catch_button_press(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == MOUSE_L)
		printf("Mouse button LEFT pressed ...\n");
	else if (t == MOUSE_R)
		printf("Mouse button RIGHT pressed ...\n");
	else if (t == MOUSE_M)
		printf("Mouse button MIDDLE pressed ...\n");
	else if (t == MOUSE_DOWN)
		printf("Mouse button DOWN pressed ...\n");
	else if (t == MOUSE_UP)
		printf("Mouse button UP pressed ...\n");
	return (0);
}

int	catch_button_release(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == MOUSE_L)
		printf("Mouse button LEFT released ...\n");
	else if (t == MOUSE_R)
		printf("Mouse button RIGHT released ...\n");
	else if (t == MOUSE_M)
		printf("Mouse button MIDDLE released ...\n");
	return (0);
}

int	catch_mouse_moves(int x, int y, t_window *w)
{
	w = save_window(NULL);
	(void)x;
	(void)y;
	//printf("Mouse moving in x: %d, y: %d ...\n", x, y);
	return (0);
}
