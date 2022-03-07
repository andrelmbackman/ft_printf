/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:23:59 by abackman          #+#    #+#             */
/*   Updated: 2022/02/22 19:47:04 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*p_strnew(char *str)
{}
char	*P_strjoin()
{}
int	convert_yes(char *str, const char *format, va_list ap)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;

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
