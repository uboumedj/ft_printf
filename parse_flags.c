/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:40:36 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 19:04:55 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** the set_flags function checks the presence of the "-+ #0" flags and stores
** the result inside the t_printf structure
*/

void		set_flags(t_printf *handler, char **str, const char *list)
{
	if (handler && str)
	{
		handler->f_min = 0;
		handler->f_add = 0;
		handler->f_spc = 0;
		handler->f_shrp = 0;
		handler->f_zero = 0;
		while (**str != '\0' && ft_strchr(list, **str) != 0)
		{
			if (**str == '-')
				handler->f_min = 1;
			else if (**str == '+')
				handler->f_add = 1;
			else if (**str == ' ')
				handler->f_spc = 1;
			else if (**str == '#')
				handler->f_shrp = 1;
			else if (**str == '0')
				handler->f_zero = 1;
			*str += 1;
		}
	}
}

/*
** the set_width function checks if there's a width formatting specification and
** stores it in the width variable of the t_printf structure. It can also take a
** '*' flag just like the original printf: if there's one, it will take the
** first available argument from the multi-variable list va_list and use it as
** the width specification.
*/

int			set_width(va_list *vlist, int *width, char **str)
{
	int			test;

	if (!(**str))
		return (0);
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

/*
** the set_length function handles the length specifiers h, hh, l, ll, j and z.
** They are stored inside the [mod] variable for further use during the flag's
** printing.
*/

void		set_length(char **str, int *mod)
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

/*
** the parse_flag function checks all the flags before the conversion/formatting
** specifier, sets all the appropriate variables using the different functions
** above, then finally stores the conversion letter inside the [spec] variable
** from the t_printf structure.
*/

char		*parse_flag(va_list *vlist, t_printf *handler, char *str, int *mod)
{
	set_flags(handler, &str, "-+ #0");
	set_width(vlist, &(handler->width), &str);
	if (ft_toneg(&(handler->width)))
		handler->f_min = 1;
	if (*str == '.')
	{
		str += 1;
		set_width(vlist, &(handler->prcsn), &str);
		if (handler->prcsn < 0)
			handler->prcsn = -1;
	}
	else
		handler->prcsn = -1;
	set_length(&str, mod);
	while (*str != '\0' && ft_strchr("hzlj", *str))
		str++;
	if (*str != '\0')
	{
		handler->spec = *str;
		str++;
	}
	return (str);
}
