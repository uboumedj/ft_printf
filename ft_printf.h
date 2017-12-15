/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:31 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/15 05:31:28 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <wchar.h>
# include "./libft/libft.h"

int   ft_printf(const char *format, ...);

size_t    strparse(const char *str, va_list *vlist);
char	check_flag(va_list *vlist, t_printf *handler, char *str);
size_t	ft_do_flag(char **str, va_list *vlist);
void    ft_old_do_flag(const char *str, int check, va_list *vlist, size_t *len);
int		ft_old_check_flags(const char c);
void	ft_do_str(const char *str, size_t *len);
void	ft_do_int(int n, size_t *len);
void	ft_do_char(char c, size_t *len);

#endif
