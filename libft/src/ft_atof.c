#include "libft.h"

static void calc_dec(double *rep, int e)
{
	while (e > 0)
	{
		*rep *= 10.0;
		e--;
	}
	while (e < 0)
	{
		*rep *= 0.1;
		e++;
	}
}

static int get_exp(char **s)
{
	int e;
	int sign;

	e = 0;
	sign = 1;
	(*s)++;
	if (**s == '+')
		(*s)++;
	else if (**s == '-')
	{
		(*s)++;
		sign = -1;
	}
	while (**s && ft_isdigit(**s))
	{
		e = (e * 10.0) + (**s - '0');
		(*s)++;
	}
	return (e * sign);
}

static int get_dec(char **s, double *rep)
{
	int i;
	i = 0;

	while ((*s)[i] && ft_isdigit((*s)[i]))
	{
		*rep = (*rep * 10.0) + ((*s)[i] - '0');
		i++;
	}
	(*s) += i;
	return (-i);
}

static void get_int(char **s, double *rep)
{
	while (**s && ft_isdigit(**s))
	{
		*rep = (*rep * 10.0) + (**s - '0');
		(*s)++;
	}
}

double	ft_atof(const char *str)
{
	char		*s;
	double		rep;
	int			e;

	s = (char *)str;
	rep = 0;
	e = 0;
	get_int(&s, &rep);
	if (*s++ == '.')
		e = get_dec(&s, &rep);
	if (*s == 'e' || *s == 'E')
		e += get_exp(&s);
	if (e != 0)
		calc_dec(&rep, e);
	return (rep);
}