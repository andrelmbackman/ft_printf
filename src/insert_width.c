/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/03/22 19:24:22 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	pad_right(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	int		y;
	
	//printf("* * * PAD_RIGHT * * * start: %i\n", start);
	x = ft_strlen(tmp);
	y = 0;
	if (p->precision != -1 && p->conv != 's' && p->zero)
		return ;
	while (y < x)
	{
		new[y] = tmp[y];
		y++;
	}
	while (x < p->width)
		new[x++] = ' ';
	new[x] = '\0';
	//ft_strdel(&p->str);
	p->str = new;
}

static void	pad_left(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	char	pad;
	
	if (!p->zero)
		start = 0;
		//printf("* * * PAD_LEFT * * * start: %i\n", start);
	x = ft_strlen(tmp);
	if (p->zero)
		pad = '0';
	else
		pad = ' ';
	if (p->precision != -1 && p->conv != 's' && p->zero)
		return ;
	while (start < (p->width - x))
		new[start++] = pad;
	x = 0;
	while (p->str[x])
		new[start++] = tmp[x++];
	new[start] = '\0';
	//ft_strdel(&tmp);
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
static void	insert_hash(t_print *p, char *new)
{
	if (p->conv == 'x' || p->conv == 'X')
	{
		new[0] = '0';
		new[1] = p->conv;
	}
	else if (p->conv == 'o' || p->conv == 'O')
		new[0] = '0';
}

char	*insert_width(t_print *p, char *tmp)
{
	char	*new;
	int		i;

	i = p->hash;
	if (p->conv == 'x' || p->conv == 'X')
		i *= 2;
	//printf("\n* * * INSERT WIDTH * * * TMP: %s\np->width: %i HASH: %i\n", tmp, p->width, p->hash);
	if (p->width < ft_strlen(tmp))
		return (tmp);
	new = (char *)malloc(p->width + i * sizeof(char));
	if (!new)
		return (tmp);
	if (p->hash)
		insert_hash(p, new);
	if (p->minus)
		pad_right(p, new, tmp, i);
	else
		pad_left(p, new, tmp, i);
	ft_strdel(&tmp);
	return (new);
}
