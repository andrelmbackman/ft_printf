/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:36 by abackman          #+#    #+#             */
/*   Updated: 2022/03/11 18:13:09 by abackman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define RESET "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define YELLOW "\033[0;33m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define BLACK "\033[0;30m"
# define WHITE "\033[0;37m"
# define FLAGS "0-+ #.*0123456789hlL"
# define SPECIFY "%cspdibouxXf"
# define ALL "0-+ #.*0123456789hlL%cspdibouxXf"

/*
** Struct in which all useful information is stored
*/

typedef struct s_print
{
	va_list	ap;
	int		i;
	int		len;
	int		width;
	int		precision;
	int		hash;
	int		zero;
	int		space;
	int		upper;
	int		plus;
	int		minus;
	int		h;
	int		l;
	int		L;
	char	f_char;
	char	length;
	char	*str;
	char	*tmp;
}	t_print;

/*
** Print functions
*/

int	pr_char(t_print *print);
int	pr_str(t_print *print);
int	pr_ptr(t_print *print);
int	pr_num(t_print *print);
int	pr_bin(t_print *print);
int	pr_oct(t_print *print);
int	pr_u(t_print *print);
int	pr_hex(t_print *print);
int	pr_float(t_print *print);
int	pr_perc(t_print *print);


/*
** Function pointer and dispatch table
*/

typedef int	(*t_able)(t_print *print);

static const t_able dispatch[13] = {
	pr_perc,
	pr_char,
	pr_str,
	pr_ptr,
	pr_num,
	pr_num,
	pr_bin,
	pr_oct,
	pr_u,
	pr_hex,
	pr_hex,
	pr_float,
	NULL
};

/*
** Other functions
*/

void	free_struct(t_print *print);
void	ft_strdel(char **as);
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		convert_no(t_print *print, const char *format);
int		convert_yes(t_print *print, const char *format);
int		get_field(const char *format, t_print *print);
char	*strnull();
char	*p_strnew(const char *format, int i);
char	*p_strjoin(char *str, const char *format, int i);
char	*strjoin_pro(char *str1, char str2[]);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa_base(int num, int base);

#endif
