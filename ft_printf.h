/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:31 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 01:58:00 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include "./libft/libft.h"

typedef struct  s_printf
{
  char  spec;
  int   prcsn;
  int   width;
  char  f_min;
  char  f_plus;
  char  f_spc;
  char  f_zero;
  char  f_shrp;

}               t_printf;

int       ft_printf(const char *format, ...);
size_t    strparse(const char *str, va_list *vlist);

char      *parse_flag(va_list *vlist, t_printf *handler, char *str, int *mod);
void      set_length(char **str, int *mod);
int       set_width(va_list *vlist, int *width, char **str);
void      set_flags(t_printf *handler, char **str, const char *list);
size_t    do_flag(char **str, va_list *vlist);

size_t    print_flag(va_list *vlist, t_printf *handler, int mod);

size_t    do_nb(va_list *vlist, int mod, t_printf *handler);
size_t    print_nb(long long int res, t_printf *handler);

size_t		do_unb(va_list *vlist, int mod, t_printf *handler);
size_t    print_unb(unsigned long long int res, t_printf *handler);

size_t    do_onb(va_list *vlist, int mod, t_printf *handler);
size_t    print_onb(unsigned long long int res, t_printf *handler);

size_t		do_hexnb(va_list *vlist, int mod, t_printf *handler);
size_t    print_hexnb(unsigned long long int res, t_printf *handler);

size_t    do_char(va_list *vlist, t_printf *handler, int mod);
size_t    print_char(wchar_t c, t_printf *handler);

size_t    do_str(va_list *vlist, t_printf *handler, int mod);

#endif
