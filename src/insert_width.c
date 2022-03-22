/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/03/22 16:30:52 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*pad_right(t_print *p, int width)
{
	int		x;
	int		y;
	char	pad;
	return (p->str);
}

static char	*pad_left(t_print *p, int width)
{
	int		x;
	int		y;
	char	pad;
	return (NULL);
}
/*
static int	count_width(t_print *p)
{
	int	x;
	int	tmp;

	x = 0;
	tmp = ft_strlen(p->str);
	if (p->width > tmp)
		x += p->width;
	else
		x += tmp;
	return (x);
}
*/
char	*insert_width(t_print *p)
{
	int		x;
	char	*new;

	x = ft_strlen(p->str);
	if (p->width < x)
		return (p->str);
	if (p->minus)
		new = pad_right(p, p->width);
	else
		new = pad_left(p, p->width);
}
