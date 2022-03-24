/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:12:35 by abackman          #+#    #+#             */
/*   Updated: 2022/03/24 15:56:33 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*strnull(t_print *p, char *str)
{
	char	*tmp;
	int		prec;

	prec = 6;
	if (str == NULL && p->precision != 0)
	{
		
		tmp = ft_strdup("(null)");
		if (p->precision > 0 && prec > p->precision)
		{
			while (prec >= p->precision)
				tmp[prec--] = '\0';
		}
	}
	else
	{
		tmp = (char *)malloc(1 * sizeof(char));
		tmp[0] = '\0';
	}
	//printf("\n* * * STRNULL * * *\np->str: \"%s\"\nnullstr: \"%s\"\n", p->str, tmp);
	return(tmp);
}

char	*zerostr(void)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

void	str_reverse(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
		j--;
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