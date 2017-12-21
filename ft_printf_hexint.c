/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 21:03:01 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/21 04:50:42 by uboumedj         ###   ########.fr       */
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
	return (print_hexnb((unsigned long long int)res, handler));
}

static int		hexnb_length(unsigned long long int nb, t_printf *handler)
{
	int		ilen;
	int		res;

	if (nb == 0)
		return (0);
	ilen = ft_unbrlenbase(nb, 16);
	res = ft_max(handler->prcsn, ilen);
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
			put_hexnb(res / 16, handler);
			ft_putchar(hexlist[res % 16]);
		}
	}
}

size_t      print_hexnb(unsigned long long int res, t_printf *handler)
{
  int		ilen;
  int		len;

  if (!handler)
    return (0);
  ilen = ft_unbrlenbase(res, 16);
  len = hexnb_length(res, handler);
  if (!(handler->f_min) && len < handler->width)
		ft_putlenchar(handler->f_zero ? '0' : ' ', handler->width - len);
  if (handler->f_shrp && res != 0)
  	ft_putstr(handler->spec == 'X' ? "0X" : "0x");
  if (ilen < handler->prcsn)
  	ft_putlenchar('0', handler->prcsn - ilen);
	if (res != 0 || handler->prcsn == -1)
	{
		if (handler->spec == 'x')
			put_hexnb(res, handler, "0123456789abcdef");
		else if (handler->spec == 'X')
			put_hexnb(res, handler, "0123456789ABCDEF");
	}
  if (handler->f_min && len < handler->width)
  	ft_putlenchar(' ', handler->width - len);
  return (ft_max(len, handler->width));
}
