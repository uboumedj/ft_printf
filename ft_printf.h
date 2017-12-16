/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:31 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/16 03:42:07 by uboumedj         ###   ########.fr       */
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

}               t_printf;

int   ft_printf(const char *format, ...);
size_t    strparse(const char *str, va_list *vlist);

char	*check_flag(va_list *vlist, t_printf *handler, char *str);
size_t	do_flag(char **str, va_list *vlist);
size_t	print_flag(va_list *vlist, t_printf handler, int mod);

void	do_str(const char *str, size_t *len);
size_t	do_nb(va_list *vlist, int mod, t_printf handler);
size_t	print_nb(long long int *res, t_printf handler);
void	do_char(char c, size_t *len);

#endif
