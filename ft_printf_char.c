/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:18:34 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 13:22:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_char(va_list *vlist, int mod, t_printf *handler)
{
	wchar_t	c;

	if (handler->spec == 'c' && mod == 3)
		handler->spec = 'C';
	if (handler->spec == 'C')
		c = (wchar_t)va_arg(*vlist, int);
	else
		c = (char)va_arg(*vlist, int);
	return (print_char((wchar_t)c, handler));
}

size_t			print_char(wchar_t c, t_printf *handler)
{
	int len;

	if (!handler)
		return (0);
	len = 1;
	if (handler->spec == 'C')
		len = ft_wcharlen(c);
	if (!(handler->f_min) && handler->width > len)
		ft_putlenchar(handler->f_zero ? '0' : ' ', handler->width - len);
	if (handler->spec == 'C')
		ft_putwchar(c);
	else
		ft_putchar(c);
	if (handler->f_min && handler->width > len)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(handler->width, len));
}
