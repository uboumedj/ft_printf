/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:35:34 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/06 18:37:26 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_unb(va_list *vlist, int mod, t_printf *handler)
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
	return (print_unb((unsigned long long int)res, handler));
}

static int		unb_length(unsigned long long int nb, int *ilen,
													t_printf *handler)
{
	int		res;

	if (nb != 0)
		*ilen = ft_unbrlenbase(nb, 10);
	res = ft_max(handler->prcsn, *ilen);
	if (nb == 0 && handler->prcsn == -1)
		res += 1;
	return (res);
}

static void		put_unb(unsigned long long int res)
{
	if (res < 10)
		ft_putchar('0' + res);
	else
	{
		put_unb(res / 10);
		ft_putchar('0' + (res % 10));
	}
}

size_t			print_unb(unsigned long long int res, t_printf *handler)
{
	int		ilen;
	int		len;

	if (!handler)
		return (0);
	ilen = 0;
	len = unb_length(res, &ilen, handler);
	if (!handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	if (res != 0 || handler->prcsn == -1)
		put_unb(res);
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
