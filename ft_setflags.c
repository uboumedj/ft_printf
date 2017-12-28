/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/24 01:38:01 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	do_flag(char **str, va_list *vlist)
{
	t_printf	handler;
	int				mod;

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

void set_flags(t_printf *handler, char **str, const char *list)
{
	if (handler && str)
	{
		while (ft_strchr(list, **str) != 0)
		{
			handler->f_min = ((**str == '-') ? 1 : 0);
			handler->f_add = ((**str == '+') ? 1 : 0);
			handler->f_spc = ((**str == ' ') ? 1 : 0);
			handler->f_shrp = ((**str == '#') ? 1 : 0);
			handler->f_zero = ((**str == '0') ? 1 : 0);
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
	if (set_width(vlist, &test, str) == 1)
		*width = test;
	return (1);
}

void set_length(char **str, int *mod)
{
	if (**str == 'h')
	{
		*str += 1;
		*mod = 2;
		if (**str == 'h')
		{
			*str += 1;
			*mod = 1;
		}
	}
	else if (**str == 'l')
	{
		*str += 1;
		*mod = 3;
		if (**str == 'l')
		{
			*str += 1;
			*mod = 4;
		}
	}
	else if (**str == 'j' || **str == 'z')
	{
		*mod = ((**str == 'j') ? 5 : 6);
		*str += 1;
	}
}

char	*parse_flag(va_list *vlist, t_printf *handler, char *str, int *mod)
{
	set_flags(handler, &str, "-+ #0");
	set_width(vlist, &(handler->width), &str);
	if (ft_toneg(&(handler->width)))
		handler->f_min = 1;
	if (*str == '.')
	{
		str += 1;
		set_width(vlist, &(handler->prcsn), &str);
	}
	else
		handler->prcsn = -1;
	set_length(&str, mod);
	handler->spec = *str;
	if (*str != '\0')
		str++;
	return (str);
}
