/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sscanf_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahuber <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:12:35 by ahuber            #+#    #+#             */
/*   Updated: 2022/09/26 16:07:55 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	skip_int(char **str, int n);
void	skip_hex(char **str, int n);
void	skip_float(char **str);

int	scan_hex(char **s, int n, int *x)
{
	char	*tmp;

	tmp = *s;
	if (n)
		tmp = ft_substr(*s, 0, n);
	*x = ft_atox(tmp);
	if (n)
		free(tmp);
	skip_hex(s, n);
	return (0);
}

int	scan_int(char **s, int len, int *n)
{
	char	*tmp;

	tmp = *s;
	if (len)
		tmp = ft_substr(*s, 0, len);
	*n = ft_atoi(tmp);
	if (len)
		free(tmp);
	skip_int(s, len);
	return (0);
}

int	scan_char(char **s, char *c)
{
	*c = **s;
	(*s)++;
	return (0);
}

int	scan_str(char **s, int n, char **str)
{
	int		i;
	char	*tmp;

	tmp = *s;
	i = -1;
	if (!n)
		n = 2147483647;
	if (n)
		tmp = ft_substr(*s, 0, n);
	while (tmp[++i] && i < n)
		if ((ft_isspace(tmp[i])))
			break ;
	*str = ft_substr(tmp, 0, i);
	if (n)
		free(tmp);
	(*s) += i;
	return (0);
}

double	scan_float(char **s, double *f)
{
	char	*str;

	str = ft_strdup(*s);
	*f = ft_atof(str);
	skip_float(s);
	free(str);
	return (0);
}
