/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/03/23 16:57:57 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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
	char	pad;
	
	x = 0;
	pad = '0';
	if (!p->zero)
	{
		start = 0;
		pad = ' ';
	}
	//printf("* * * PAD_LEFT * * * start: %i\n", start);
	x = ft_strlen(tmp);
	if (p->precision != -1 && p->conv != 's' && p->zero)
		return (tmp);
	while (start < (p->width - x))
		new[start++] = pad;
	x = 0;
	while (p->str[x])
		new[start++] = tmp[x++];
	new[start] = '\0';
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

char	*insert_width(t_print *p, char *tmp, int free)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if (p->conv == 'o' || p->conv == 'O' || p->conv == 'x' || p->conv == 'X')
		i = p->hash;
	if (p->conv == 'x' || p->conv == 'X')
		i *= 2;
	//printf("\n* * * INSERT WIDTH1 * * * TMP: \"%s\"\nP->STR: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", tmp, p->str, i, p->width, p->hash, p->minus);
	if (p->width < ft_strlen(tmp))
		return (ft_strdup(tmp));
	new = (char *)malloc(p->width + i * sizeof(char));
	if (!new)
		return (ft_strdup(tmp));
	if (p->hash)
		insert_hash(p, new);
	if (p->minus)
		new = pad_right(p, new, tmp, i);
	else
		new = pad_left(p, new, tmp, i);
	if (free)
		ft_strdel(&tmp);
	//printf("\n* * * INSERT WIDTH2 * * * NEW: \"%s\"\nP->STR: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, p->str, i, p->width, p->hash, p->minus);
	return (new);
}
