/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycornamu <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:30:58 by ycornamu          #+#    #+#             */
/*   Updated: 2022/08/30 16:05:50 by ycornamu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	catch_key_ext(int t, t_window *w);

int	catch_key(int t, t_window *w)
{
	w = save_window(NULL);
	if (t == KEY_ESC || t == KEY_ESC_LNX)
		exit(clean_win(w));
	else if (t == KEY_UP || t == KEY_UP_LNX)
		printf("Key UP pressed...\n");
	else if (t == KEY_DOWN || t == KEY_DOWN_LNX)
		printf("Key DOWN pressed...\n");
	else if (t == KEY_W || t == KEY_W_LNX)
		printf("Key W pressed...\n");
	else if (t == KEY_A || t == KEY_A_LNX)
		printf("Key A pressed...\n");
	else if (t == KEY_S || t == KEY_S_LNX)
		printf("Key S pressed...\n");
	else if (t == KEY_D || t == KEY_D_LNX)
		printf("Key D pressed...\n");
	else if (t == KEY_Q || t == KEY_Q_LNX)
		printf("Key Q pressed...\n");
	else if (t == KEY_E || t == KEY_E_LNX)
		printf("Key E pressed...\n");
	else
		catch_key_ext(t, w);
	return (0);
}

static void	catch_key_ext(int t, t_window *w)
{
	(void)w;
	if (t == KEY_X || t == KEY_X_LNX)
		printf("Key X pressed...\n");
	else if (t == KEY_Y || t == KEY_Y_LNX)
		printf("Key Y pressed...\n");
	else if (t == KEY_Z || t == KEY_Z_LNX)
		printf("Key Z pressed...\n");
	else if (t == KEY_I || t == KEY_I_LNX)
		printf("Key I pressed...\n");
	else if (t == KEY_P || t == KEY_P_LNX)
		printf("Key P pressed...\n");
}
