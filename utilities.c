/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:35 by abackman          #+#    #+#             */
/*   Updated: 2022/02/17 16:56:23 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strjoin_pro(char *str1, char str2[])
{
	size_t	i;
	size_t	j;
	char	*str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	i = (ft_strlen(str1) + ft_strlen(str2));
	str = (char *)malloc((i + 1) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
		str[i++] = str2[j++];
	str[i] = '\0';
	free(str1);
	return (str);
}
