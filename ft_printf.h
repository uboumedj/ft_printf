/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:37:31 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/12 10:21:26 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);

int		ft_strparse(const char *str, int *len, va_list *vlist);
int		ft_check_flags(const char c);
void	ft_do_flag(const char *str, int check, va_list *vlist, int *len);
void	ft_do_str(const char *str, int *len);
void	ft_do_int(int n, int *len);
void	ft_do_char(char c, int *len);

#endif
