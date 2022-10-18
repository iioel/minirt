#include "minirt.h"
#include <unistd.h>

int	print_error(char *str)
{
	if (!str)
		return (0);
	write(2, str, ft_strlen(str));
	return (1);
}

void	error(t_window *w)
{
	t_list *l;

	if (w->objs == NULL)
		exit(1);
	l = w->objs;
	while (l)
	{
		(t_object *)(l->content)->error(l->content);
		l = l->next;
	}
	
}