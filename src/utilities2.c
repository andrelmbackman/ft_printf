/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:11:25 by abackman          #+#    #+#             */
/*   Updated: 2022/04/25 12:41:10 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*fill_zeros(char *str, int total, long long num, int x)
{
	int		y;
	char	*new;

	y = 0;
	if (num < 0)
		new = (char *)malloc((total + 2) * sizeof(char));
	else
		new = (char *)malloc((total + 1) * sizeof(char));
	if (!new)
		return (NULL);
	if (num < 0)
	{
		new[0] = '-';
		str[0] = '0';
		y = 1;
		x--;
	}	
	while (y < (total - x))
		new[y++] = '0';
	x = 0;
	while (str[x])
		new[y++] = str[x++];
	new[y] = '\0';
	return (new);
}

char	*zeropad(char *str, int total, long long num)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (total < len)
	{
		if (str[0] == '0')
			str[0] = '\0';
		return (str);
	}
	else
		new = fill_zeros(str, total, num, len);
	if (!new)
		return (str);
	else
	{
		ft_strdel(&str);
		return (new);
	}
}

char	*insert_space_only(t_print *p, char *str)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = (unsigned char)str[0];
	ft_strdel(&str);
	str = (char *)malloc((size_t)p->width + 1 * sizeof(char));
	if (!str)
		return (NULL);
	if (p->minus)
	{
		str[i++] = c;
		while (i < p->width)
			str[i++] = ' ';
	}
	else
	{
		while (i < p->width - 1)
			str[i++] = ' ';
		str[i++] = c;
	}
	str[i] = '\0';
	return (str);
}

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (1);
	else
		return (0);
}

void	init_struct(t_print *print)
{
	print->check_neg = 0;
	print->w_save = 0;
	print->p_save = 0;
	print->width = 0;
	print->precision = -1;
	print->hash = 0;
	print->zero = 0;
	print->fl_zero = 0;
	print->space = 0;
	print->upper = 0;
	print->plus = 0;
	print->minus = 0;
	print->h = 0;
	print->l = 0;
	print->cap_l = 0;
	print->z = 0;
	print->conv = 0;
}
