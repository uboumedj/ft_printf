/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 07:18:08 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/06 18:40:37 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_bnb(va_list *vlist, int mod, t_printf *handler)
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
	return (print_bnb((unsigned long long int)res, handler));
}

static int		bnb_length(unsigned long long int nb, int *ilen,
													t_printf *handler)
{
	int		res;

	if (nb != 0)
		*ilen = ft_unbrlenbase(nb, 2);
	res = ft_max(handler->prcsn, *ilen);
	if (nb == 0 && handler->prcsn == -1)
		res += 1;
	return (res);
}

static void		put_bnb(unsigned long long int res)
{
	if (res < 2)
		ft_putchar('0' + res);
	else
	{
		put_bnb(res / 2);
		ft_putchar('0' + res % 2);
	}
}

size_t			print_bnb(unsigned long long int res, t_printf *handler)
{
	int		ilen;
	int		len;

	if (!handler)
		return (0);
	ilen = 0;
	len = bnb_length(res, &ilen, handler);
	if (!(handler->f_min) && len < handler->width)
		ft_putlenchar((handler->f_zero && handler->prcsn == -1) ?
			'0' : ' ', handler->width - len);
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	else if (handler->f_shrp && res != 0)
		ft_putchar('0');
	if (res != 0 || handler->prcsn == -1 || handler->f_shrp)
		put_bnb(res);
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
