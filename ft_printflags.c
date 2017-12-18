/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 01:30:54 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/17 03:08:44 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_flag(va_list *vlist, t_printf *handler, int mod)
{
	if (handler->spec == '%')
		return(print_char('%', handler));
	else if (handler->spec == 'd' || handler->spec == 'i')
		return (do_nb(vlist, handler, mod));
	else if (handler->spec == 'c' || handler->spec == 'C')
		return (do_char(vlist, handler, mod));
	else if (handler->spec == 's' || handler->spec == 'S')
		return (do_str(vlist, handler, mod));
}
