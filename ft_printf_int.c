/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 17:48:59 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/16 03:42:02 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	do_nb(va_list *vlist, int mod, t_printf handler)
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
	return (ft_putnb(&res, handler));
}

size_t	print_nb(long long int *res, t_printf handler)
{

}
