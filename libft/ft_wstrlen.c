/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:41:59 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/02 14:24:25 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_wstrlen(const wchar_t *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		len += ft_wcharlen(*str);
		str++;
	}
	return (len);
}
