/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   as_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/04/22 17:00:16 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	as_pr_char(t_print *print)
{
	char			*str;
	unsigned char	c;

	c = (unsigned char)va_arg(print->ap, int);
	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (-1);
	str[0] = c;
	str[1] = '\0';
	if (print->width)
	{
		if (!ft_isprint(c))
			str = insert_space_only(print, str);
		else
			str = insert_width(print, str, 1);
	}
	if (print->str != NULL)
		print->str = strjoin_pro(print->str, str, 1);
	else if (print->str == NULL)
		print->str = str;
	if (print->width)
		return (print->width);
	else
		return (1);
}

char	*p_strnew(const char *format, int i)
{
	int		j;
	char	*str;

	j = 0;
	str = (char *)malloc(i * sizeof(char));
	if (!str)
		return (NULL);
	while (j < i)
	{
		str[j] = format[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*p_strjoin(char *str, const char *format, int i)
{
	char	*new;
	int		j;
	int		k;
	int		l;

	j = ft_strlen(str) + i;
	new = (char *)malloc(j + 1 * sizeof(char));
	if (!new)
		return (NULL);
	k = 0;
	l = 0;
	while (str[k])
	{
		new[k] = str[k];
		k++;
	}
	while (k < j)
		new[k++] = format[l++];
	new[k] = '\0';
	ft_strdel(&str);
	return (new);
}

int	as_convert_yes(t_print *print, const char *format)
{
	int	x;
	int	ret;

	x = 0;
	ret = 0;
	init_struct(print);
	if (ft_strchr(FLAGS, format[print->i]))
		get_field(format, print);
	if (format[print->i] >= 'A' && format[print->i] <= 'Z')
		print->upper = 1;
	while (format[print->i] != SPECIFY[x] && x < 26)
		x++;
	if (format[print->i] == SPECIFY[x])
	{
		print->conv = format[print->i];
		if (print->conv == 'c')
			ret = as_pr_char(print);
		else
			ret = g_dispatch[x](print);
	}
	else
		print->i--;
	return (ret);
}

int	as_convert_no(t_print *print, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (print->str != NULL)
		print->str = p_strjoin(print->str, format, i);
	else
		print->str = p_strnew(format, i);
	print->ret += i;
	return (i);
}
