/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/17 03:26:17 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	do_flag(char **str, va_list *vlist)
{
	t_printf	handler;
	int mod;

	if (**ptr == '%')
	{
		(*ptr)++;
		if (**ptr != '\0')
		{
			*ptr = parse_flag(vlist, &handler, *str, &mod);
			return (print_flag(vlist, &handler, mod));
		}
	}
	return (0);
}

void set_flags(t_printf *handler, char **str, const char *list)
{
	if (handler && str)
	{
		while (ft_strchr(list, **str) != 0)
		{
			if (**str == '-')
				format->f_min = 1;
			else if (**str == '+')
				format->f_plus = 1;
			else if (**str == ' ')
				format->f_spc = 1;
			else if (**str == '#')
				format->f_shrp = 1;
			else if (**str == '0')
				format->f_zero = 1;
			*str += 1;
		}
	}
}

int		set_width(va_list *vlist, int *width, char **str)
{
	int test;

	if (**str == '*')
	{
		*width = va_arg(*vlist, int);
		*str += 1;
	}
	else if ((ft_strtonum(str, width)) == 0)
		return (0);
	if (set_width(vlist, test, str) == 1)
		*width = test;
	return (1);
}

char	*parse_flag(va_list *vlist, t_printf *handler, char *str)
{
	set_flags(handler, &str, "-+ #0");
	set_width(vlist, &(handler->width), &str);
	if (ft_toneg(&(handler->width)))
		handler->f_min = 1;
	handler->spec = *str;
	if (*str != '\0')
		str++;
	return (str);
}
