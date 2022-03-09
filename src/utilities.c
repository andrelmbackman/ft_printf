/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 15:49:35 by abackman          #+#    #+#             */
/*   Updated: 2022/03/09 14:11:32 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	free_struct(t_print *print)
{
	if (!print)
		return ;
	else
	{
		if (print->str)
		{
			free(print->str);
			print->str = NULL;
		}
		free(print);
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (i <= j)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*strjoin_pro(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*str;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	i = (ft_strlen(str1) + ft_strlen(str2));
	str = (char *)malloc((i + 1) * sizeof(char));
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
	ft_strdel(&str1);
	ft_strdel(&str2);
	return (str);
}
