/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/03/11 18:12:18 by abackman         ###   ########.fr       */
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
