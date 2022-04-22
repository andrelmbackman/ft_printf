/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:30:20 by abackman          #+#    #+#             */
/*   Updated: 2022/04/22 17:31:01 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	print_conversion(t_print *p, int bytes)
{
	int	ret;

	ret = 0;
	if (p->conv == 'c')
		p->ret += write(p->fd, p->str, bytes);
	else
		p->ret += write(p->fd, p->str, (size_t)ft_strlen(p->str));
	ft_strdel(&p->str);
}

int	convert_yes(t_print *print, const char *format)
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
		if (print->conv == 'c' && print->str != NULL)
			ft_strdel(&print->str);
		ret += g_dispatch[x](print);
		if (print->str != NULL)
			print_conversion(print, ret);
	}
	else
		print->i--;
	return (1);
}

int	convert_no(t_print *print, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	print->ret += write(print->fd, format, i);
	return (i);
}