/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 18:30:20 by abackman          #+#    #+#             */
/*   Updated: 2022/04/01 19:21:20 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
		ret += dispatch[x](print);
		//printf("* * * CONVERT_YES * * *\nSPECIFY[x] = %c i: %i\np->i: %i\nstr: \"%s\"\nret: %i\n", SPECIFY[x], x, print->i, print->str, ret);
		print->ret += write(print->fd, print->str, ret);
		ft_strdel(&print->str);
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