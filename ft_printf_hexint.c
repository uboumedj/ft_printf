/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:03:01 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/09 13:43:11 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_hexnb(va_list *vlist, int mod, t_printf *handler)
{
	unsigned long long int	res;

	if (mod == 0)
		res = (unsigned int)va_arg(*vlist, long long int);
	else if (mod == 1)
		res = (unsigned char)va_arg(*vlist, unsigned long long int);
	else if (mod == 2)
		res = (unsigned short)va_arg(*vlist, unsigned long long int);
	else if (mod == 3)
		res = (unsigned long)va_arg(*vlist, unsigned long long int);
	else if (mod == 4)
		res = (unsigned long long)va_arg(*vlist, unsigned long long int);
	else if (mod == 5)
		res = (uintmax_t)va_arg(*vlist, unsigned long long int);
	else if (mod == 6)
		res = (size_t)va_arg(*vlist, unsigned long long int);
	else
		return (0);
	return (print_hexnb((unsigned long long int)res, handler));
}

static int		hexnb_length(unsigned long long int nb, int *ilen,
														t_printf *handler)
{
	int						res;

	if (nb != 0)
		*ilen = ft_unbrlenbase(nb, 16);
	res = ft_max(handler->prcsn, *ilen);
	if (nb == 0 && handler->prcsn == -1)
		res += 1;
	if (nb != 0 && handler->f_shrp)
		res += 2;
	return (res);
}

static void		put_hexnb(unsigned long long int res, t_printf *handler,
													char *hexlist)
{
	if (hexlist)
	{
		if (res < 16)
			ft_putchar(hexlist[res]);
		else
		{
			put_hexnb(res / 16, handler, hexlist);
			ft_putchar(hexlist[res % 16]);
		}
	}
}

size_t			print_hexnb(unsigned long long int res, t_printf *handler)
{
	int			ilen;
	int			len;

	if (!handler)
		return (0);
	ilen = 0;
	len = hexnb_length(res, &ilen, handler);
	if (!(handler->f_min) && len < handler->width && (!(handler->f_zero)
				|| !(handler->prcsn == -1)))
		ft_putlenchar(' ', handler->width - len);
	if (handler->f_shrp && res != 0)
		ft_putstr(handler->spec == 'X' ? "0X" : "0x");
	if (!(handler->f_min) && len < handler->width && handler->f_zero
			&& handler->prcsn < 0)
		ft_putlenchar('0', handler->width - len);
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	if (res != 0 || handler->prcsn == -1)
		put_hexnb(res, handler, (handler->spec == 'x' ?
						"0123456789abcdef" : "0123456789ABCDEF"));
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
