/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/02/28 15:15:35 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*p_strnew(char *str, const char *format, int i)
{
	int	j;

	j = 0;
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

static char *p_strjoin(char *str, const char *format, int i)
{
	char	*new;
	int		j;

	if (!str && !format)
		return (NULL);
	j = ft_strlen(str) + i;
	new = (char *)malloc(j + 1 * sizeof(char));
	if (!new)
		return (NULL);
	j = 0;
	while (str[j])
	{
		new[j] = str[j];
		j++;
	}
	new += j;
	j = 0;
	while (j <= i)
	{
		new[j] = format[j];
		j++;
	}
	free(str);
	return (new);	
}

int	convert_yes(t_print *print, const char *format, va_list ap)
{
	int	i;

	i = 0;
	while (*format != SPECIFY[i])
		i++;
	return (dispatch[i](print));
}

int	convert_no(char *str, const char *format)
{
	int	i;

	i = 0;
	while (format[i] && format[i] != '%')
		i++;
	if (!str)
		str = p_strnew(str, format, i);
	else
		str = p_strjoin(str, format, i);
	return (i);
}
