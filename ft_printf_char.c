/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 10:18:34 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 02:08:24 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	do_char(va_list *vlist, t_printf *handler, int mod)
{
	wint_t	c;

	if (handler->spec == 'c' && mod == 3)
		handler->spec = 'C';
	if (handler->spec == 'C')
		c = (wchar_t)va_arg(*vlist, wint_t);
	else if (handler->spec == 'c')
		c = (char)va_arg(*vlist, char);
	return (print_char(&c, handler));
}

size_t	print_char(wchar_t c, t_printf *handler)
{
	int len;

	if (!handler)
		return (0);
	if (handler->spec == 'C')
		len = 2; //à changer
	else
		len = 1;
	if (!(handler->f_min) && handler->width > len)
		ft_putlenchar(handler->f_zero ? '0' : ' ', handler->width - len);
	if (handler->spec == 'C')
		ft_putchar(c); //à changer
	else
		ft_putchar(c);
	if (handler->f_min && handler->width > len)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(handler->width, len));
}
