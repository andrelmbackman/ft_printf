/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 14:49:25 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

	if (!str || !format)
		return (NULL);
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
	int	i;
	
	i = 0;
	init_struct(print);
	//i += get_field(format, print);
	while (*format != SPECIFY[i])
		i++;
	return (dispatch[i](print));
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
