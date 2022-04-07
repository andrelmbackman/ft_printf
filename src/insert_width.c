/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:06:15 by abackman          #+#    #+#             */
/*   Updated: 2022/04/07 19:05:31 by abackman         ###   ########.fr       */
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

static char	*swap_space(char *new)
{
	int		i;
	
	i = 0;
	while (new[i])
	{
		if (new[i] == ' ')
		{
			new[i] = new[0];
			new[0] = ' ';
			break ;
		}
		i++;
	}
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
/* 	if (!p->zero || ((p->conv == 'd' || p->conv == 'i') && p->precision > 0 &&\
	!p->zero && !p->minus && !p->w_save && !p->check_neg)) */
	if ((!p->zero && p->conv != 'd' && p->conv != 'i' && p->conv != 'f') || \
	(!p->zero && !p->minus && !p->p_save))
	{
		//printf("\n\n\nHERE\n\n\n");
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
	if ((p->conv == 'd' || p->conv == 'i' || p->conv == 'f') && p->space)
		new = swap_space(new);
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
	{
		i = p->hash;
		if (p->conv == 'x' || p->conv == 'X')
			i *= 2;
	}
	else if (p->conv == 'i' || p->conv == 'd' || p->conv == 'f')
	{
		if (tmp[0] == '+' || tmp[0] == '-')
			i = 1;
		if (tmp[0] == ' ')
			i = 1;
	}
/* 	else if ((p->conv == 'i' || p->conv == 'd') && (tmp[0] == '-' ||\
	tmp[0] == '+' || tmp[0] == ' ')) */
	return (i);
}
/* static char	*insert_width_str(t_print *p, char *tmp, int free)
{
	char	*new;
	int		start;
	
	start = 0;
	if (tmp[0] == '+' || tmp[0] == '-' || tmp[0] == ' ')
		start++;
	
} */

char	*insert_width(t_print *p, char *tmp, int free)
{
	char	*new;
	int		i;

	new = NULL;
	i = width_start(p, tmp);
	if (!p->width)
		return (tmp);
	//printf("\n* * * INSERT WIDTH1 * * *\nNEW: \"%s\"\nTMP: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, tmp, i, p->width, p->hash, p->minus);
	if (p->width <= ft_strlen(tmp) && (p->conv != 'd' || p->conv != 'i' || \
	p->conv != 'f') && p->width)
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
