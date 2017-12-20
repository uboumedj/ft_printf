/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:24:01 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/20 02:01:12 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	do_str(va_list *vlist, t_printf *handler, int mod)
{
	void *str;

	if (handler->spec == 's' && mod == 3)
		handler->spec = 'S';
	str = va_arg(*vlist, void *);
	return (print_str(str, handler));
}
