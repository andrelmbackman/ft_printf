/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/03/30 14:09:44 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*pad_right(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	
	x = ft_strlen(tmp);
	if (p->precision != -1 && p->conv != 's' && p->zero)
		return (tmp);
	while (start < x)
	{
		new[start] = tmp[start];
		start++;
	}
	while (x < p->width)
		new[x++] = ' ';
	new[x] = '\0';
	//printf("\n* * * PAD_RIGHT * * *\nnew: \"%s\"\ntmp: \"%s\"\np->str: \"%s\"\n", new, tmp, p->str);
	return (new);
}

static char	*pad_left(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	int 	save;
	char	pad;
	
	pad = '0';
	x = ft_strlen(tmp);
	new = ft_strcpy(new, (const char *)tmp);
	if (!p->zero || ((p->conv == 'd' || p->conv == 'i') && p->precision > 0))
	{
		start = 0;
		pad = ' ';
	}
	save = start;
	//printf("\n* * * PAD_LEFT1 * * *\nNEW: %s\nTMP: %s\nstart: %i\nx: %i\nwidth: %i\n", new, tmp, start, x, p->width);
	//if (p->precision != -1 && p->conv != 's')
	//	return (tmp);
	while (start < (p->width - x + save))
		new[start++] = pad;
	x = save;
	while (tmp[x])
		new[start++] = tmp[x++];
	new[start] = '\0';
	//printf("* * * PAD_LEFT2 * * * NEW: %s TMP: %s\n", new, tmp);
	return (new);
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
static char	*insert_hash(t_print *p, char *tmp)
{
	if (p->conv == 'x' || p->conv == 'X')
	{
		tmp = strjoin_pro("0x", tmp, 2);
		if (p->conv == 'X')
			tmp[1] = 'X';
	}
	else if (p->conv == 'o' || p->conv == 'O')
	{
		tmp = strjoin_pro("0", tmp, 2);
	}
	//printf("\nINSERT_HASH\nTMP: %s\n", tmp);
	return (tmp);
}
*/
static int	width_start(t_print *p, char *tmp)
{
	int	i;

	i = 0;
	if (p->conv == 'o' || p->conv == 'O' || p->conv == 'x' || p->conv == 'X')
		i = p->hash;
	if (p->conv == 'x' || p->conv == 'X')
		i *= 2;
	else if ((p->conv == 'i' || p->conv == 'd') && (tmp[0] == '-' ||\
	tmp[0] == '+'))
		i = 1;
	return (i);
}

char	*insert_width(t_print *p, char *tmp, int free)
{
	char	*new;
	int		i;

	new = NULL;
	i = width_start(p, tmp);
	//printf("\n* * * INSERT WIDTH1 * * *\nNEW: \"%s\"\nTMP: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, tmp, i, p->width, p->hash, p->minus);
	if (p->width <= ft_strlen(tmp))
		return (tmp);
	new = (char *)malloc(p->width + i + 1 * sizeof(char));
	if (!new)
		return (tmp);
	//if (p->hash && p->width)
	//	tmp = insert_hash(p, tmp);
	//printf("\n* * * INSERT WIDTH2 * * *\nNEW: \"%s\"\nTMP: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, tmp, i, p->width, p->hash, p->minus);
	if (p->minus)
		new = pad_right(p, new, tmp, 0);
	else
		new = pad_left(p, new, tmp, i);
	//printf("\n* * * INSERT WIDTH3 * * *\nNEW: \"%s\"\nTMP: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, tmp, i, p->width, p->hash, p->minus);
	if (free == 1)
		ft_strdel(&tmp);
	return (new);
}
