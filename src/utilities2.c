/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:11:25 by abackman          #+#    #+#             */
/*   Updated: 2022/03/11 16:03:40 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


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