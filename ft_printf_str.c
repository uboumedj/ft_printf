/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:24:01 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 18:17:55 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_str(va_list *vlist, int mod, t_printf *handler)
{
	char	*str;

	if (handler->spec == 's' && mod == 3)
		handler->spec = 'S';
	str = va_arg(*vlist, char *);
	return (print_str(str, handler));
}

static int		wstr_len(char *str, t_printf *handler)
{
	if (str)
	{
		if (handler->prcsn != -1)
		{
			if (handler->spec == 'S')
				return (ft_wstrnlen((wchar_t *)str, handler->prcsn));
			else if (handler->spec == 's')
				return (ft_strnlen(str, handler->prcsn));
		}
		else
		{
			if (handler->spec == 'S')
				return (ft_wstrlen((wchar_t *)str));
			else if (handler->spec == 's')
				return (ft_strlen(str));
		}
	}
	return (0);
}

size_t			print_str(char *str, t_printf *handler)
{
	int		len;

	if (!handler)
		return (0);
	if (!str)
	{
		if (handler->spec == 's')
			str = "(null)";
		else if (handler->spec == 'S')
			str = (char *)L"(null)";
	}
	len = wstr_len(str, handler);
	if (!(handler->f_min) && len < handler->width)
		ft_putlenchar(handler->f_zero ? '0' : ' ', handler->width - len);
	if (str)
	{
		if (handler->spec == 'S')
			ft_putlenwstr((wchar_t *)str, len);
		else if (handler->spec == 's')
			ft_putlenstr(str, len);
	}
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
