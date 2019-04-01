/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:55 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** do_flag function is called when the parsing of the format string finds a
** % flag. It starts by parsing the flag with parse_flag, then prints the
** correct conversion/formatting before letting the parsing of the format string
** continue.
*/

size_t		do_flag(char **str, va_list *vlist)
{
	t_printf	handler;
	int			mod;

	if (**str == '%')
	{
		(*str)++;
		if (**str != '\0')
		{
			mod = 0;
			*str = parse_flag(vlist, &handler, *str, &mod);
			return (print_flag(vlist, &handler, mod));
		}
	}
	return (0);
}
