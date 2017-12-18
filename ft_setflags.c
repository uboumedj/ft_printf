/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setflags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/18 02:03:23 by uboumedj         ###   ########.fr       */
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
			mod = 0;
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

void set_length(char **str, int *mod)
{
	if (*str == 'h')
	{
		*str += 1;
		*mod = 2;
		if (*str == 'h')
		{
			*str += 1;
			*mod = 1;
		}
	}
	else if (*str == 'l')
	{
		*str += 1;
		*mod = 3;
		if (*str == 'l')
		{
			*str += 1;
			*mod = 4;
		}
	}
	else if (*str == 'j' || *str == 'z')
	{
		*str += 1;
		*mod = ((*str == 'j') ? 5 : 6);
	}
}

char	*parse_flag(va_list *vlist, t_printf *handler, char *str, int *mod)
{
	set_flags(handler, &str, "-+ #0");
	set_width(vlist, &(handler->width), &str);
	if (ft_toneg(&(handler->width)))
		handler->f_min = 1;
	if (*str = '.')
		set_width(vlist, &(handler->prcsn), &str);
	else
		handler->prcsn = -1;
	set_length(&str, mod);
	handler->spec = *str;
	if (*str != '\0')
		str++;
	return (str);
}