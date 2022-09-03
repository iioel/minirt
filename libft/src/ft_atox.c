#include "libft.h"

int	ft_atox(const char *str)
{
	char	*s;
	int		rep;

	s = (char *)str;
	rep = 0;
	while ((*s <= '9' && *s >= '0') || (*s <= 'f' && *s >= 'a'))
	{		
		if (*s <= '9' && *s >= '0')
			rep = (rep * 16) + (*s - '0');
		else if (*s <= 'f' && *s >= 'a')
			rep = (rep * 16) + ((*s - 'a') + 10);
		s++;
	}
	return (rep);
}