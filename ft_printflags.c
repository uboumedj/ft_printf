/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:30:54 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 15:07:51 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_flag(va_list *vlist, t_printf *handler, int mod)
{
	if (handler->spec == '%')
		return (print_char('%', handler));
	else if (handler->spec == 'd' || handler->spec == 'i')
		return (do_nb(vlist, mod, handler));
	else if (handler->spec == 'D' || handler->spec == 'U'
				|| handler->spec == 'O')
		return (do_lnb(vlist, mod, handler));
	else if (handler->spec == 'u')
		return (do_unb(vlist, mod, handler));
	else if (handler->spec == 'o')
		return (do_onb(vlist, mod, handler));
	else if (handler->spec == 'x' || handler->spec == 'X')
		return (do_hexnb(vlist, mod, handler));
	else if (handler->spec == 'c' || handler->spec == 'C')
		return (do_char(vlist, mod, handler));
	else if (handler->spec == 's' || handler->spec == 'S')
		return (do_str(vlist, mod, handler));
	else if (handler->spec == 'p')
		return (do_ptr(vlist, mod, handler));
	else if (handler->spec == 'b')
		return (do_bnb(vlist, mod, handler));
	return (0);
}
