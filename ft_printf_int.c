/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:48:59 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 08:38:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				do_nb(va_list *vlist, int mod, t_printf *handler)
{
	long long int res;

	if (mod == 0)
		res = (int)va_arg(*vlist, long long int);
	else if (mod == 1)
		res = (signed char)va_arg(*vlist, long long int);
	else if (mod == 2)
		res = (short)va_arg(*vlist, long long int);
	else if (mod == 3)
		res = (long)va_arg(*vlist, long long int);
	else if (mod == 4)
		res = (long long)va_arg(*vlist, long long int);
	else if (mod == 5)
		res = (intmax_t)va_arg(*vlist, long long int);
	else if (mod == 6)
		res = (size_t)va_arg(*vlist, long long int);
	return (print_nb((long long int)res, handler));
}

static int		nb_length(long long int nb, t_printf *handler)
{
	int		ilen;
	int		res;

	ilen = ft_nbrlen(nb);
	res = ft_max(handler->prcsn, ilen);
	if (nb < 0 || (nb == 0 && handler->prcsn == -1))
		res += 1;
	if ((nb > 0 || (nb == 0 && handler->prcsn == -1))
		&& (handler->f_add || handler->f_spc))
		res += 1;
	return (res);
}

static void		put_nb(long long int res)
{
	if (res < 0)
		res = -res;
	if (res < 10)
		ft_putchar('0' + res);
	else
	{
		put_nb(res / 10);
		ft_putchar('0' + (res % 10));
	}
}

size_t				print_nb(long long int res, t_printf *handler)
{
	int		ilen;
	int		len;

	if (!handler)
		return (0);
	ilen = ft_nbrlen(res);
	len = nb_length(res, handler);
	if (len < handler->width && !(handler->f_min) && (!(handler->f_zero)
				|| !(handler->prcsn == -1)))
		ft_putlenchar(' ', handler->width - len);
	if (res < 0)
		ft_putchar('-');
	else if (res >= 0 && (handler->f_add || handler->f_spc))
			ft_putchar(handler->f_add ? '+' : ' ');
	if (len < handler->width && !(handler->f_min) && handler->f_zero
				&& handler->prcsn < 0)
		ft_putlenchar('0', handler->width - len);
	if (ilen < format->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	if (res != 0 || handler->prcsn == -1)
		put_nb(res);
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
