/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 10:36:23 by uboumedj          #+#    #+#             */
/*   Updated: 2017/12/12 10:58:05 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_strparse(const char *str, int *len, va_list *vlist)
{
	int			i;
	int			check;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			*len += 1;
		}
		else
		{
			i++;
			while ((check = ft_check_flags(str[i])) < 2 || check > 8 )
				i++;
			ft_do_flag(&str[i], check, vlist, len);
		}
		i++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		vlist;
	int			i;
	int			len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(vlist, str);
	if (ft_strparse(str, &len, &vlist) == -1)
		return (-1);
	va_end(vlist);
	return (len);
}
