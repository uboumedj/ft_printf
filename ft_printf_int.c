/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:48:59 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/09 12:48:48 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			do_nb(va_list *vlist, int mod, t_printf *handler)
{
	long long int	res;

	if (mod == 0)
		res = va_arg(*vlist, int);
	else if (mod == 1)
		res = (signed char)va_arg(*vlist, int);
	else if (mod == 2)
		res = (short)va_arg(*vlist, int);
	else if (mod == 3)
		res = va_arg(*vlist, long int);
	else if (mod == 4)
		res = va_arg(*vlist, long long int);
	else if (mod == 5)
		res = va_arg(*vlist, intmax_t);
	else if (mod == 6)
		res = va_arg(*vlist, size_t);
	else
		return (0);
	return (print_nb(res, handler));
}

size_t			do_lnb(va_list *vlist, int mod, t_printf *handler)
{
	long int		res;

	mod = 0;
	res = va_arg(*vlist, long int);
	if (handler->spec == 'D')
		return (print_nb((long long int)res, handler));
	else if (handler->spec == 'U')
		return (print_unb((unsigned long long int)res, handler));
	else if (handler->spec == 'O')
		return (print_onb((unsigned long long int)res, handler));
	return (0);
}

static int		nb_length(long long int nb, t_printf *handler)
{
	int				ilen;
	int				res;

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
	unsigned long long int temp;

	if (res < 0)
		temp = -res;
	else
		temp = res;
	if (temp < 10)
		ft_putchar('0' + temp);
	else
	{
		put_nb(temp / 10);
		ft_putchar('0' + (temp % 10));
	}
}

size_t			print_nb(long long int res, t_printf *handler)
{
	int				ilen;
	int				len;

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
	if (ilen < handler->prcsn)
		ft_putlenchar('0', handler->prcsn - ilen);
	if (res != 0 || handler->prcsn == -1)
		put_nb(res);
	if (handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
	return (ft_max(len, handler->width));
}
