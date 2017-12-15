/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <uboumedj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:36:23 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/15 04:53:51 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t		strparse(const char *str, va_list *vlist)
{
	size_t	len;
	char	*tmp;
	char	*start;

	len = 0;
	tmp = (char *)str;
	start = tmp;
	while (*tmp != '\0')
	{
		if (*tmp != '\0' && *tmp != '%')
		{
			len++;
			tmp++;
		}
		else if (*tmp == '%')
		{
			ft_putstr_i(start, tmp - start);
			len += ft_do_flag(&tmp, vlist);
			start = tmp;
		}
	}
	ft_putstr_i(start, tmp - start);
	return (len);
}

int		ft_printf(const char *format, ...)
{
	va_list		vlist;
	int			i;
	size_t			len;

	i = 0;
	len = 0;
	if (format)
	{
		va_start(vlist, format);
		len = strparse(format, &len, &vlist);
		va_end(vlist);
	}
	return (len);
}
