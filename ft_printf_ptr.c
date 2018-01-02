/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 02:30:59 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:48:53 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_ptr(va_list *vlist, int mod, t_printf *handler)
{
	void	*ptr;

	ptr = va_arg(*vlist, void *);
	return (print_ptr((size_t)ptr, handler));
}

static size_t	ptr_ilen(size_t ptr)
{
	size_t	res;

	if (ptr == 0)
		return (0);
	res = 1;
	while (ptr >= 16)
	{
		ptr /= 16;
		res++;
	}
	return (res);
}

static size_t	ptr_len(size_t ptr, size_t ilen, t_printf *handler)
{
	size_t	len;

	len = ft_max(handler->prcsn, ilen) + 2;
	if (ptr == 0 && handler->prcsn == -1)
		len++;
	return (len);
}

static void		put_ptr(size_t ptr, char *hexlist)
{
	if (hexlist)
	{
		if (ptr < 16)
			ft_putchar(hexlist[ptr]);
		else
		{
			put_ptr(ptr / 16, hexlist);
			ft_putchar(hexlist[ptr % 16]);
		}
	}
}

size_t			print_ptr(size_t ptr, t_printf *handler)
{
	int			ilen;
	int			len;

	if (!handler)
		return (0);
	ilen = ptr_ilen(ptr);
	len = ptr_len(ptr, ilen, handler);
	if (!(handler->f_min) && len < handler->width && (!(handler->f_zero)
				|| handler->prcsn != -1))
		ft_putlenchar(' ', handler->width - len);
	ft_putstr("0x");
	if (!(handler->f_min) && len < handler->width && handler->f_zero
				&& handler->prcsn == -1)
		ft_putlenchar('0', handler->width - len);
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	if (ptr != 0 || handler->prcsn == -1)
		put_ptr(ptr, "0123456789abcdef");
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
