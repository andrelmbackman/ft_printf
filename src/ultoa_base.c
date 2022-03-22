/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultoa_base.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:03:06 by abackman          #+#    #+#             */
/*   Updated: 2022/03/16 12:16:55 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static size_t	ultoa_base_len(unsigned long n, int base)
{
	size_t	length;

	length = 1;
	n /= (unsigned long)base;
	while (n)
	{
		n /= (unsigned long)base;
		length++;
	}
	return (length);
}

static char	*ultoa_str(char *str, unsigned long num, int base, int up)
{
	int				i;
	unsigned long	tmp;

	i = 0;
	tmp = 0;
	while (num != 0)
	{
		tmp = num % (unsigned long)base;
		if (tmp > 9)
			str[i] = tmp - 10 + up + 'a';
		else
			str[i] = tmp + '0';
		num = num / (unsigned long)base;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ultoa_base(unsigned long num, int base, t_print *print)
{
	char			*str;
	int				up;
	unsigned long	n;

	up = 0;
	n = num;
	if (print->upper)
		up = -32;
	if (num == 0)
		return (zerostr());
	str = (char *)malloc((ultoa_base_len(num, base) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str = ultoa_str(str, n, base, up);
	str_reverse(str);
	return (str);
}
