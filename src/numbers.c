/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:15:34 by abackman          #+#    #+#             */
/*   Updated: 2022/04/19 14:24:12 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

double	init_dot(long double num, long long whole, int prec)
{
	//double		power10[10];
	double		power;
	double		dot;

	power = 1;
	dot = 0;
	while (dot++ < prec)
		power *= 10;
	
	/* if (prec > 9)
		prec = 9;
	power10[0] = 1;
	power10[1] = 10;
	power10[2] = 100;
	power10[3] = 1000;
	power10[4] = 10000;
	power10[5] = 100000;
	power10[6] = 1000000;
	power10[7] = 10000000;
	power10[8] = 100000000;
	power10[9] = 1000000000;
 */	//dot = (num - whole) * power10[prec];
	dot = (num - whole) * power;
	//printf("\n* * INIT DOT * *\nnum: %Lf\nwhole: %lli\nprec: %i\ndot: %f\n", num, whole, prec, dot);
	return (dot);
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

static char	*pad_right(t_print *p, char *new, char *tmp, int start)
{
	int		x;
	
	x = ft_strlen(tmp);
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
	//printf("\nPAD LEFT\np->zero: %i\np->psave: %i\n\n", p->zero, p->p_save);
/* 	if (!p->zero || ((p->conv == 'd' || p->conv == 'i') && p->precision > 0 &&\
	!p->zero && !p->minus && !p->w_save && !p->check_neg)) */
	if (!p->fl_zero)//(!p->zero && !p->minus && !p->p_save))
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
	if (p->space)
		new = swap_space(new);
	//printf("* * * PAD_LEFT2 * * * NEW: %s TMP: %s\n", new, tmp);
	return (new);
}

char	*fl_width(t_print *p, char *str)
{
	char	*new;
	int		i;

	i = 0;
	if (!p->width)
		return (str);
	//printf("\n{%s}\n", str);
	while (!ft_isdigit((int)str[i]))
		i++;
	//printf("\ni: %i\n", i);
	new = (char *)malloc(p->width + i + 1 * sizeof(char));
	if (!new)
		return (str);
	if (p->minus)
		new = pad_right(p, new, str, 0);
	else
		new = pad_left(p, new, str, i);
	//printf("\n* * * INSERT WIDTH3 * * *\nNEW: \"%s\"\nTMP: \"%s\"\nstart: %i\np->width: %i\nHASH: %i\nMINUS: %i\n", new, tmp, i, p->width, p->hash, p->minus);
	ft_strdel(&str);
	return (new);
}