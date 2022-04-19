/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:11:25 by abackman          #+#    #+#             */
/*   Updated: 2022/04/19 14:10:28 by abackman         ###   ########.fr       */
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
	//printf("1 FILL_ZEROS\nnew: %s\nstr: %s\ny: %i\nx: %i\ntotal: %i\n", new, str, y, x, total);
	while (y < (total - x))
		new[y++] = '0';
	x = 0;
	while (str[x])
		new[y++] = str[x++];
	new[y] = '\0';
	//printf("2 FILL_ZEROS\nnew: %s\nstr: %s\ny: %i\nx: %i\ntotal: %i\n", new, str, y, x, total);
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
	//printf("\nINSERT_SPACE_ONLY\n[%s]\n", str);
	//write(1, "[", 1);
	//write(1, str, 5);
	//write(1, "]", 1);
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
	print->L = 0;
	print->z = 0;
	print->conv = 0;
}

/*
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	ch1;
	unsigned char	ch2;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0') && (s2[i] != '\0') && n > 0)
	{
		i++;
		n--;
	}
	if (n == 0)
	{
		ch1 = (unsigned char)s1[i - 1];
		ch2 = (unsigned char)s2[i - 1];
		return (ch1 - ch2);
	}
	else
	{
		ch1 = (unsigned char)s1[i];
		ch2 = (unsigned char)s2[i];
		return (ch1 - ch2);
	}
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*str;

	i = ft_strlen(s1);
	str = (char *)malloc((i + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
*/