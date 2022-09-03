/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2021/11/05 17:38:29 by yalthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		scan_hex(char **s, int n, int *x);
int		scan_int(char **s, int len, int *n);
int		scan_char(char **s, char *c);
int		scan_str(char **s, int n, char **str);
double	scan_float(char **s, double *f);
void	skip_int(char **str, int n);

int	skip_arg(char **str, char **format)
{
	int	i;

	i = 0;
	while ((*format)[i] && (*str)[i])
	{
		if ((*format)[i] != (*str)[i])
			break ;
		++i;
	}
	*str += i;
	*format += i;
	return (i);
}

int	scan_arg(char **str, char **format, va_list args)
{
	int	n;

	n = 0;
	if (ft_isdigit(**format))
	{
		n = ft_atoi(*format);
		skip_int(format, 0);
	}
	if (**format == 'i')
		scan_int(str, n, va_arg(args, int *));
	else if (**format == 'x')
		scan_hex(str, n, va_arg(args, int *));
	else if (**format == 'c')
		scan_char(str, va_arg(args, char *));
	else if (**format == 's')
		scan_str(str, n, va_arg(args, char **));
	else if (**format == 'f')
		scan_float(str, va_arg(args, double *));
	return (0);
}

int	ft_sscanf(char *str, char *format, ...)
{
	int		ret;
	va_list	args;

	va_start(args, format);
	ret = 0;
	if (!str || !format)
		return (0);
	while (*format != '\0')
	{
		skip_arg(&str, &format);
		if (*format == '%')
		{
			format++;
			if (scan_arg(&str, &format, args))
				return (-1);
			ret++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}