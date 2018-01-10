/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uboumedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 13:49:39 by uboumedj          #+#    #+#             */
/*   Updated: 2018/01/10 18:14:56 by uboumedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int			ft_wstrnlen(const wchar_t *str, int n)
{
	int		charlen;
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (*str != '\0' && len < n)
	{
		charlen = ft_wcharlen(*str);
		if (len + charlen > n)
			return (len);
		len += charlen;
		str++;
	}
	return (len);
}
