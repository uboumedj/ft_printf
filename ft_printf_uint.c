/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:35:34 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/19 19:02:46 by uboumedj         ###   ########.fr       */
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
	return (print_unb(&res, handler));
}

static int		unb_length(unsigned long long int nb, t_printf *handler)
{
	int		ilen;
	int		res;

	ilen = ft_nbrlen(nb);
	res = ft_max(handler->prcsn, ilen);
	if (nb == 0 && handler->prcsn == -1))
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

size_t      print_unb(unsigned long long int res, t_printf *handler)
{
  int		ilen;
	int		len;

	if (!handler)
		return (0);
	ilen = ft_nbrlen(res);
	len = unb_length(res, handler);
  if (!handler->f_min && len < handler->width)
		ft_putlenchar(' ', handler->width - len);
  if (ilen < handler->prcsn)
  	ft_putlenchar('0', handler->prcsn - ilen);
  if (res != 0 || handler->prcsn == -1)
		ft_putunb(res);
  if (handler->f_min && len < handler->width)
  	ft_putlenchar(' ', handler->width - len);
  return (ft_max(len, handler->width));
}
