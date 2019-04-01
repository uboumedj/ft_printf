/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:36:23 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 17:29:04 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** strparse is basically the central function inside ft_printf. It will parse
** the format string, stopping when it reaches a % flag (i.e %d, %s, etc...) or
** when it reaches the end of the string. It then prints the whole part of
** the string it parsed. Printing a %flag is handled by the do_flag function
** and the strparse loop resumes after the flag is handled.
*/

size_t		strparse(const char *str, va_list *vlist)
{
	size_t		len;
	char		*tmp;
	char		*start;

	len = 0;
	tmp = (char *)str;
	start = tmp;
	while (*tmp != '\0')
	{
		if (*tmp != '\0' && *tmp != '%')
		{
			tmp++;
			len++;
		}
		else if (*tmp == '%')
		{
			ft_putlenstr(start, tmp - start);
			len += do_flag(&tmp, vlist);
			start = tmp;
		}
	}
	ft_putlenstr(start, tmp - start);
	return (len);
}

/*
** main function ft_printf. Just like printf, it takes a format string as its
** first argument, then a variable number of arguments thanks to the va_list
** type. It returns the length of the printed string.
*/

int			ft_printf(const char *format, ...)
{
	va_list	vlist;
	size_t	len;

	len = 0;
	if (format)
	{
		va_start(vlist, format);
		len = strparse(format, &vlist);
		va_end(vlist);
	}
	return (len);
}
