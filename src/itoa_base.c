/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 17:03:16 by abackman          #+#    #+#             */
/*   Updated: 2022/03/28 20:05:46 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	itoa_base_len(long long n, int base)
{
	size_t	length;

	length = 1;
	if (n < 0)
	{
		n *= -1;
		length++;
		if (base == 16)
			return (8);
		if (base == 8)
			return (11);
	}
	n /= (long long)base;
	while (n)
	{
		n /= (long long)base;
		length++;
	}
	return (length);
}

static char	*itoa_str(char *str, long long num, int base, int up)
{
	int			i;
	long long	tmp;

	i = 0;
	tmp = 0;
	while (num != 0)
	{
		tmp = num % (long long)base;
		if (tmp > 9)
			str[i] = tmp - 10 + up + 'a';
		else
			str[i] = tmp + '0';
		num = num / (long long)base;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_itoa_base(long long num, int base, t_print *print)
{
	char		*str;
	int			up;
	long long	n;

	n = num;
	up = 0;
	if (print->upper)
		up = -32;
	if (num == 0)
		return (zerostr());
	if (num == (-9223372036854775807 - 1))
		return (ft_strdup("-9223372036854775808"));
	str = (char *)malloc((itoa_base_len(n, base) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
		n *= -1;
	str = itoa_str(str, n, base, up);
	up = 0;
	while (str[up])
		up++;
	if (num < 0)
		str[up++] = '-';
	str[up] = '\0';
	str_reverse(str);
	return (str);
}
