/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:00:34 by abackman          #+#    #+#             */
/*   Updated: 2022/03/22 13:24:50 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"


void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	while (len > 0)
	{
		*ptr = c;
		ptr++;
		len--;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

int	ft_strcmp(const char *s1, const char *s2)
{	
	int				i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0') && (s2[i] != '\0'))
	{	
		i++;
	}
	c1 = (unsigned char)s1[i];
	c2 = (unsigned char)s2[i];
	return (c1 - c2);
}

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(src);
	j = 0;
	while (j < len)
	{
		if (src[j] == '\0')
		{
			dst[j] = '\0';
			break ;
		}
		dst[j] = src[j];
		j++;
	}
	if (i < len)
	{
		ft_bzero((dst + j), (len - i));
	}
	return (dst);
}