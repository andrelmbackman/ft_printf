/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/03/15 18:28:34 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_struct(t_print *print)
{
	print->len = 0;
	print->width = 0;
	print->precision = -1;
	print->hash = 0;
	print->zero = 0;
	print->space = 0;
	print->upper = 0;
	print->plus = 0;
	print->minus = 0;
	print->h = 0;
	print->l = 0;
	print->L = 0;
	print->f_char = 0;
	print->length = 0;
}

char	*p_strnew(const char *format, int i)
{
	int		j;
	char	*str;
	
	j = 0;
	//printf("P_STRNEW\n");
	str = (char *)malloc(i + 1 * sizeof(char));
	if (!str)
		return (NULL);
	while (j <= i)
	{
		str[j] = format[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char *p_strjoin(char *str, const char *format, int i)
{
	char	*new;
	int		j;
	int		k;
	int		l;
	
	j = ft_strlen(str) + i;
	//printf("P_STRINGJOIN j: %i\n", j);
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
	//printf("stringjoin: \"%s\"\n", new);
	ft_strdel(&str);
	return (new);
}

int	convert_yes(t_print *print, const char *format)
{
	int	x;
	
	x = 0;
	init_struct(print);
	if (ft_strchr(FLAGS, format[print->i]))
		get_field(format, print);
	while (format[print->i] != SPECIFY[x])
		x++;
	if (format[print->i] == SPECIFY[x])
		return (dispatch[x](print));
	else
		print->i--;
	return (0);
}

int	convert_no(t_print *print, const char *format)
{
	int	i;

	i = 0;
	while (format[i] != '\0' && format[i] != '%')
		i++;
	if (print->str)
		print->str = p_strjoin(print->str, format, i);
	else
		print->str = p_strnew(format, i);

	return (i);
}
