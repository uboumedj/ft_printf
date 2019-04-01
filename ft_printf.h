/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:31 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:45 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "./libft/inc/libft.h"

/*
** the s_printf structure is basically used every time a flag is found, and
** contains all the necessary information from the flag.
** * spec stores the letter of the type of conversion used (d, x, u, s, ...)
** * prcsn stores the conversion's precision
** * width obviously stores the conversion's width
** * all subsequent variables are initialised at 0 at first, and set to 1 if the
**	 flag is used (f_min: '-', f_add: '+', f_spc: ' ', f_zero: '0', f_shrp: '#')
*/

typedef struct	s_printf
{
	char	spec;
	int		prcsn;
	int		width;
	char	f_min;
	char	f_add;
	char	f_spc;
	char	f_zero;
	char	f_shrp;
}				t_printf;

/*
** core functions for parsing, flag setting and printing
*/

int				ft_printf(const char *format, ...);
size_t			strparse(const char *str, va_list *vlist);

char			*parse_flag(va_list *vlist, t_printf *handler, char *str,
																	int *mod);
void			set_length(char **str, int *mod);
int				set_width(va_list *vlist, int *width, char **str);
void			set_flags(t_printf *handler, char **str, const char *list);
size_t			do_flag(char **str, va_list *vlist);

size_t			print_flag(va_list *vlist, t_printf *handler, int mod);

/*
** integer conversion (%d and %i) handling
*/

size_t			do_nb(va_list *vlist, int mod, t_printf *handler);
size_t			print_nb(long long int res, t_printf *handler);

/*
** long conversion (%D, %U, %O) handling
*/

size_t			do_lnb(va_list *vlist, int mod, t_printf *handler);

/*
** unsigned conversion (%u) handling
*/

size_t			do_unb(va_list *vlist, int mod, t_printf *handler);
size_t			print_unb(unsigned long long int res, t_printf *handler);

/*
** octal conversion (%o) handling
*/

size_t			do_onb(va_list *vlist, int mod, t_printf *handler);
size_t			print_onb(unsigned long long int res, t_printf *handler);

/*
** hexadecimal conversion (%x and %X) handling
*/

size_t			do_hexnb(va_list *vlist, int mod, t_printf *handler);
size_t			print_hexnb(unsigned long long int res, t_printf *handler);

/*
** binary conversion (%b) handling (not in original printf)
*/

size_t			do_bnb(va_list *vlist, int mod, t_printf *handler);
size_t			print_bnb(unsigned long long int res, t_printf *handler);

/*
** pointer adress (%p) handling
*/

size_t			do_ptr(va_list *vlist, int mod, t_printf *handler);
size_t			print_ptr(size_t ptr, t_printf *handler);

/*
** character (%c and %C) handling
*/

size_t			do_char(va_list *vlist, int mod, t_printf *handler);
size_t			print_char(wchar_t c, t_printf *handler);

/*
** string of characters (%s and %S) handling
*/

size_t			do_str(va_list *vlist, int mod, t_printf *handler);
size_t			print_str(char *str, t_printf *handler);

#endif
