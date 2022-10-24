/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:30:58 by ycornamu          #+#    #+#             */
/*   Updated: 2022/09/26 18:23:14 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "action.h"

int	catch_key(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == KEY_ESC || t == KEY_ESC_LNX)
		exit(clean_win(w));
	else if (t == KEY_UP || t == KEY_UP_LNX)
		look(w, UP);
	else if (t == KEY_DOWN || t == KEY_DOWN_LNX)
		look(w, DOWN);
	else if (t == KEY_LEFT || t == KEY_LEFT_LNX)
		look(w, LEFT);
	else if (t == KEY_RIGHT || t == KEY_RIGHT_LNX)
		look(w, RIGHT);
	else if (t == KEY_W || t == KEY_W_LNX)
		move(w, FW);
	else if (t == KEY_A || t == KEY_A_LNX)
		move(w, LEFT);
	else if (t == KEY_S || t == KEY_S_LNX)
		move(w, BACK);
	else if (t == KEY_D || t == KEY_D_LNX)
		move(w, RIGHT);
	return (0);
}
