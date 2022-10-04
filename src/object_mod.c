#include "minirt.h"

int catch_key_obj(int t, t_window *w)
{
	w = save_window(NULL);
	printf("%i\n", t);
	if (t == KEY_UP || t == KEY_UP_LNX)	
		((t_sphere *)w->selected_obj)->diameter++;
	else if (t == KEY_W || t == KEY_W_LNX)
		((t_sphere *)w->selected_obj)->point.x++;
	else if (t == KEY_A || t == KEY_A_LNX)
		((t_sphere *)w->selected_obj)->point.z++;
	else if (t == KEY_S || t == KEY_S_LNX)
		((t_sphere *)w->selected_obj)->point.x--;
	else if (t == KEY_D || t == KEY_D_LNX)
		((t_sphere *)w->selected_obj)->point.z--;
	if (t == KEY_ENTER)
		define_hooks(w);
	w->rd_i = RENDER_STEPS;
	return (0);
}

static void define_hook_obj(t_window *w)
{
	mlx_hook(w->w, 2, (1L << 0), catch_key_obj, w);
}

void select_obj(t_window *w, int x, int y)
{
	t_ray		r;

	w->rd_i = 1;
	r = pix2ray(w, x, y);
	printf("ICI2\n");
	get_nearest_obj(&(w->selected_obj), r, w->objs);
	if (w->selected_obj)
		define_hook_obj(w);
}