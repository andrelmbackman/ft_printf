/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abackman <abackman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:07:36 by abackman          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/03/09 12:01:48 by abackman         ###   ########.fr       */
=======
/*   Updated: 2022/03/01 15:54:25 by abackman         ###   ########.fr       */
>>>>>>> 3223fece55e77f0bda70863d36dc732ccafcdd93
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define EOC "\033[0m"
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
	va_list		ap;
	int			len;
<<<<<<< HEAD
	int			width;
	int			precision;
	int			hash;
	int			zero;
	int			space;
	int			upper;
	char		f_char;
	char		length;
	char		*str;
	char		*tmp;
=======
	int			length;
	int			width;
	int			precision;
	char		f_char;
	char		upper;
	char		*str;
>>>>>>> 3223fece55e77f0bda70863d36dc732ccafcdd93
}	t_print;

/*
** Print functions
*/

int	pr_perc(t_print *print);
int	pr_char(t_print *print);
int	pr_str(t_print *print);
int	pr_ptr(t_print *print);
int	pr_num(t_print *print);
int	pr_bin(t_print *print);
int	pr_oct(t_print *print);
int	pr_u(t_print *print);
int	pr_hex(t_print *print);
int	pr_float(t_print *print);


/*
** Function pointer and dispatch table
*/

typedef int	(*t_able)(t_print *print);

<<<<<<< HEAD
static const t_able dispatch[13] = {
=======
static const t_able dispatch[26] = {
>>>>>>> 3223fece55e77f0bda70863d36dc732ccafcdd93
	pr_perc,
	pr_char,
	pr_str, /* if str == NULL, print (null) */
	pr_ptr,
	pr_num,
	pr_num,
	pr_bin,
	pr_oct,
	pr_u,
	pr_hex,
	pr_hex,
	pr_float,
<<<<<<< HEAD
	NULL
=======
>>>>>>> 3223fece55e77f0bda70863d36dc732ccafcdd93
};

/*
** Other functions
*/

<<<<<<< HEAD
void	free_struct(t_print *print);
void	init_struct(t_print *print);
void	ft_strdel(char **as);
int		ft_strlen(const char *str);
int		ft_isdigit(int c);
int		convert_no(t_print *print, const char *format);
int		convert_yes(t_print *print, const char *format);
char	*strnull();
char	*p_strnew(const char *format, int i);
char	*p_strjoin(char *str, const char *format, int i);
char	*strjoin_pro(char *str1, char str2[]);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
=======
void	ft_strdel(char **as);
int		ft_strlen(char *str);
int		ft_isdigit(int c);
int		convert_no(char *str, const char *format);
int		convert_yes(t_print *print, const char *format);
char	*strjoin_pro(char *str1, char str2[]);
>>>>>>> 3223fece55e77f0bda70863d36dc732ccafcdd93

#endif
